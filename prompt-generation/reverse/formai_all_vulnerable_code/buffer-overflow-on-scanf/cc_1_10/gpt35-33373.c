//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

// Define a struct to hold email data
typedef struct {
    char name[50];
    char email[50];
} Email;

// Define a struct to hold the email list
typedef struct {
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailList;

// Merge sort helper function to sort the email list by name
void merge(Email* emails, int start, int mid, int end) {
    int i, j, k;
    Email temp[end-start+1];

    i = start;
    j = mid+1;
    k = 0;

    while (i <= mid && j <= end) {
        if (strcmp(emails[i].name, emails[j].name) < 0) {
            temp[k] = emails[i];
            i++;
        } else {
            temp[k] = emails[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = emails[i];
        i++;
        k++;
    }

    while (j <= end) {
        temp[k] = emails[j];
        j++;
        k++;
    }

    for (i = start; i <= end; i++) {
        emails[i] = temp[i-start];
    }
}

// Merge sort function to sort the email list by name
void mergeSort(Email* emails, int start, int end) {
    int mid;

    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(emails, start, mid);
        mergeSort(emails, mid+1, end);
        merge(emails, start, mid, end);
    }
}

// Add an email to the email list
void addEmail(EmailList* emailList, char* name, char* email) {
    if (emailList->num_emails < MAX_EMAILS) {
        Email new_email;
        strcpy(new_email.name, name);
        strcpy(new_email.email, email);
        emailList->emails[emailList->num_emails] = new_email;
        emailList->num_emails++;
        printf("Email added successfully.\n");
    } else {
        printf("Email list is full.\n");
    }
}

// Remove an email from the email list by email address
void removeEmail(EmailList* emailList, char* email) {
    int i;
    for (i = 0; i < emailList->num_emails; i++) {
        if (strcmp(emailList->emails[i].email, email) == 0) {
            int j;
            for (j = i; j < emailList->num_emails-1; j++) {
                emailList->emails[j] = emailList->emails[j+1];
            }
            emailList->num_emails--;
            printf("Email removed successfully.\n");
            return;
        }
    }
    printf("Email not found.\n");
}

// Print the email list sorted by name
void printEmails(EmailList* emailList) {
    mergeSort(emailList->emails, 0, emailList->num_emails-1);
    int i;
    printf("Name\t\tEmail\n");
    for (i = 0; i < emailList->num_emails; i++) {
        printf("%s\t\t%s\n", emailList->emails[i].name, emailList->emails[i].email);
    }
}

int main() {
    EmailList emailList = {0};
    int choice;

    do {
        printf("\n1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print emails sorted by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], email[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(&emailList, name, email);
                break;
            }
            case 2: {
                char email[50];
                printf("Enter email: ");
                scanf("%s", email);
                removeEmail(&emailList, email);
                break;
            }
            case 3:
                printEmails(&emailList);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}