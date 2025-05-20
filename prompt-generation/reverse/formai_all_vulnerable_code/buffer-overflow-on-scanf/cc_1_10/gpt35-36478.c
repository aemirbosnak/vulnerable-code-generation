//FormAI DATASET v1.0 Category: Email Client ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to display menu options
void menu() {
    printf("Email Client Options:\n");
    printf("1. Compose Email\n");
    printf("2. Inbox\n");
    printf("3. Sent Items\n");
    printf("4. Drafts\n");
    printf("5. Exit\n");
}

// email structure
struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[1000];
};

// function to compose email
void composeEmail() {
    struct email newEmail;

    printf("From: ");
    scanf("%s", newEmail.sender);

    printf("To: ");
    scanf("%s", newEmail.receiver);

    printf("Subject: ");
    scanf("%s", newEmail.subject);

    printf("\nEnter message: ");
    scanf("%s", newEmail.message);

    // write to file
    FILE *fp;
    fp = fopen("drafts.txt", "a");
    fprintf(fp, "%s\n%s\n%s\n%s\n", newEmail.sender, newEmail.receiver, newEmail.subject, newEmail.message);
    fclose(fp);
    printf("\nEmail saved as draft!\n");
}

// function to display emails in file
void displayEmails(char filename[]) {
    FILE *fp;
    char readfile[500];

    fp = fopen(filename, "r");
    if (fp != NULL) {
        while (fgets(readfile, 500, fp) != NULL) {
            printf("\n%s", readfile);
        }
        fclose(fp);
    }
    else {
        printf("\n-%s is empty-\n", filename);
    }
}

// function to read recent emails
void inbox() {
    displayEmails("inbox.txt");
}

// function to read sent emails
void sentItems() {
    displayEmails("sent.txt");
}

// function to read draft emails
void drafts() {
    displayEmails("drafts.txt");
}

int main() {
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                inbox();
                break;
            case 3:
                sentItems();
                break;
            case 4:
                drafts();
                break;
            case 5:
                printf("Exiting Email Client...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}