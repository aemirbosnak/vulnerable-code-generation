//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
/* Mailing list manager program in C */
/* Written in a Donald Knuth style */

#include <stdio.h>
#include <stdlib.h>

#define MAX_EMAILS 1000 /* Maximum number of email addresses in a list */
#define MAX_NAME_LENGTH 50 /* Maximum length of a subscriber's name */
#define MAX_EMAIL_LENGTH 100 /* Maximum length of an email address */

/* Structure definition for a subscriber */
typedef struct {
    char name[MAX_NAME_LENGTH+1];
    char email[MAX_EMAIL_LENGTH+1];
} Subscriber;

/* Structure definition for a mailing list */
typedef struct {
    int num_subscribers;
    Subscriber subscribers[MAX_EMAILS];
} MailingList;

/* Function prototypes */
void display_menu();
void add_subscriber(MailingList *list);
void remove_subscriber(MailingList *list);
void view_subscribers(MailingList *list);
int validate_email(char *email);

int main() {
    MailingList list = {0}; /* Empty list to start with */
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_subscriber(&list);
                break;
            case 2:
                remove_subscriber(&list);
                break;
            case 3:
                view_subscribers(&list);
                break;
            case 4:
                /* Exit program */
                printf("Thank you for using our mailing list manager!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    
    return 0;
}

/* Function to display the main menu */
void display_menu() {
    printf("\nMain Menu\n");
    printf("---------\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. View subscribers\n");
    printf("4. Exit\n");
}

/* Function to add a new subscriber to the list */
void add_subscriber(MailingList *list) {
    /* Check if list is already full */
    if (list->num_subscribers >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }
    
    Subscriber new_subscriber;
    char email[MAX_EMAIL_LENGTH+1];
    
    /* Get subscriber information */
    printf("Enter subscriber name: ");
    scanf("%s", new_subscriber.name);
    printf("Enter subscriber email address: ");
    scanf("%s", email);
    
    /* Validate email address */
    if (!validate_email(email)) {
        printf("Invalid email address!\n");
        return;
    }
    
    /* Add subscriber to list */
    strcpy(new_subscriber.email, email);
    list->subscribers[list->num_subscribers++] = new_subscriber;
    
    printf("Subscriber added successfully!\n");
}

/* Function to remove a subscriber from the list */
void remove_subscriber(MailingList *list) {
    /* Check if list is empty */
    if (list->num_subscribers == 0) {
        printf("Mailing list is empty!\n");
        return;
    }
    
    char email[MAX_EMAIL_LENGTH+1];
    int i, j, found = 0;
    
    /* Get email address of subscriber to be removed */
    printf("Enter email address of subscriber to be removed: ");
    scanf("%s", email);
    
    /* Search for subscriber in list */
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        /* Remove subscriber from list */
        for (j = i; j < list->num_subscribers-1; j++) {
            list->subscribers[j] = list->subscribers[j+1];
        }
        list->num_subscribers--;
        
        printf("Subscriber removed successfully!\n");
    } else {
        printf("Subscriber not found!\n");
    }
}

/* Function to view all subscribers in the list */
void view_subscribers(MailingList *list) {
    /* Check if list is empty */
    if (list->num_subscribers == 0) {
        printf("Mailing list is empty!\n");
        return;
    }
    
    printf("Subscribers\n");
    printf("-----------\n");
    
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

/* Function to validate email addresses */
int validate_email(char *email) {
    int at_count = 0;
    int dot_count = 0;
    int i = 0;
    
    while (email[i] != '\0') {
        if (email[i] == '@') {
            at_count++;
        }
        if (email[i] == '.') {
            dot_count++;
        }
        i++;
    }
    
    if (at_count == 1 && dot_count >= 1) {
        return 1;
    } else {
        return 0;
    }
}