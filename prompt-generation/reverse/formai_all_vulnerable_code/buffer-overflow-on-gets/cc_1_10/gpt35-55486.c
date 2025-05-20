//FormAI DATASET v1.0 Category: Email Client ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

#define MAX_EMAILS 100

/* Defining a structure for emails */
typedef struct {
    char subject[100];
    char from[50];
    char to[50];
    char message[1000];
} Email;

/* Function prototypes */
void display_menu();
int get_choice();
void read_emails(Email emails[MAX_EMAILS], int *count);
void send_email(Email emails[MAX_EMAILS], int *count);
void view_emails(Email emails[MAX_EMAILS], int count);
void search_emails(Email emails[MAX_EMAILS], int count);
void sort_emails(Email emails[MAX_EMAILS], int count);

int main() {
    int choice, count = 0;
    Email emails[MAX_EMAILS];

    /* Loop for displaying menu and processing user choice */
    do {
        display_menu();
        choice = get_choice();

        switch(choice) {
            case 1: read_emails(emails, &count);
                    break;
            case 2: send_email(emails, &count);
                    break;
            case 3: view_emails(emails, count);
                    break;
            case 4: search_emails(emails, count);
                    break;
            case 5: sort_emails(emails, count);
                    break;
            case 6: printf("Exiting program...\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

/* Function to display menu */
void display_menu() {
    printf("\n====== C Email Client =======\n");
    printf("\n1. Read emails");
    printf("\n2. Send email");
    printf("\n3. View emails");
    printf("\n4. Search emails");
    printf("\n5. Sort emails");
    printf("\n6. Exit");
    printf("\n\nEnter your choice: ");
}

/* Function to get user choice */
int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

/* Function to read emails */
void read_emails(Email emails[MAX_EMAILS], int *count) {
    printf("\nEnter the number of emails to read: ");
    int num, i;
    scanf("%d", &num);

    /* Loop for reading multiple emails */
    for(i = 0; i < num; i++) {
        if(*count == MAX_EMAILS) {
            printf("Maximum limit reached.\n");
            break;
        }

        printf("\nEmail %d - Enter details:", *count+1);
        getchar(); // to clear newline character from buffer
        printf("\nFrom: ");
        gets(emails[*count].from);
        printf("To: ");
        gets(emails[*count].to);
        printf("Subject: ");
        gets(emails[*count].subject);
        printf("Message: ");
        gets(emails[*count].message);

        (*count)++;
    }
}

/* Function to send email */
void send_email(Email emails[MAX_EMAILS], int *count) {
    if(*count == MAX_EMAILS) {
        printf("Maximum limit reached.\n");
        return;
    }

    printf("\nEnter details of email to send:");
    getchar(); // to clear newline character from buffer
    printf("\nFrom: ");
    gets(emails[*count].from);
    printf("To: ");
    gets(emails[*count].to);
    printf("Subject: ");
    gets(emails[*count].subject);
    printf("Message: ");
    gets(emails[*count].message);

    printf("\nEmail sent successfully!\n");
    (*count)++;
}

/* Function to view emails */
void view_emails(Email emails[MAX_EMAILS], int count) {
    if(count == 0) {
        printf("\nNo emails to display.\n");
        return;
    }

    int i;
    for(i = 0; i < count; i++) {
        printf("\nEmail %d details:", i+1);
        printf("\nFrom: %s", emails[i].from);
        printf("\nTo: %s", emails[i].to);
        printf("\nSubject: %s", emails[i].subject);
        printf("\nMessage: %s", emails[i].message);
        printf("\n");
    }
}

/* Function to search for emails */
void search_emails(Email emails[MAX_EMAILS], int count) {
    if(count == 0) {
        printf("\nNo emails to search.\n");
        return;
    }

    char search[100];
    printf("\nEnter search term (from, to, subject, message): ");
    getchar(); // to clear newline character from buffer
    gets(search);

    int i, found = 0;
    for(i = 0; i < count; i++) {
        if(strstr(emails[i].from, search) || strstr(emails[i].to, search) || strstr(emails[i].subject, search) || strstr(emails[i].message, search)) {
            printf("\nEmail %d details:", i+1);
            printf("\nFrom: %s", emails[i].from);
            printf("\nTo: %s", emails[i].to);
            printf("\nSubject: %s", emails[i].subject);
            printf("\nMessage: %s", emails[i].message);
            printf("\n");
            found = 1;
        }
    }

    if(!found) {
        printf("\nNo matching emails found.\n");
    }
}

/* Function to sort emails */
void sort_emails(Email emails[MAX_EMAILS], int count) {
    if(count == 0) {
        printf("\nNo emails to sort.\n");
        return;
    }

    int i, j;
    Email temp;
    for(i = 0; i < count-1; i++) {
        for(j = i+1; j < count; j++) {
            if(strcmp(emails[i].subject, emails[j].subject) > 0) {
                temp = emails[i];
                emails[i] = emails[j];
                emails[j] = temp;
            }
        }
    }

    printf("\nEmails sorted successfully!\n");
}