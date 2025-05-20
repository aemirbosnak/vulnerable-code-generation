//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct email {
    char sender[100];
    char recipient[100];
    char subject[200];
    char message[1000];
};

int main() {
    struct email inbox[100];
    int count = 0, choice;
    char temp[1000];
    printf("*** Welcome to the Future Email Client ***\n\n");

    while (1) {
        printf("1. Compose  2. View inbox  3. Delete email 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n-----Compose Email-----\n");
                printf("Sender email address: ");
                scanf("%s", inbox[count].sender);
                printf("Recipient email address: ");
                scanf("%s", inbox[count].recipient);
                printf("Subject: ");
                scanf("%s", inbox[count].subject);
                printf("Message: ");
                fgets(temp, sizeof(temp), stdin);
                fgets(inbox[count].message, sizeof(inbox[count].message), stdin);
                printf("\nMessage sent!\n\n");
                count++;
                break;

            case 2:
                printf("\n-----Inbox-----\n");
                if (count == 0) {
                    printf("--No emails in inbox.--\n\n");
                    break;
                }
                for (int i = 0; i < count; i++) {
                    printf("Email %d\n", i+1);
                    printf("From: %s\n", inbox[i].sender);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Message: %s", inbox[i].message);
                    printf("\n");
                }
                printf("\n");
                break;

            case 3:
                printf("\n-----Delete Email-----\n");
                if (count == 0) {
                    printf("--No emails in inbox.--\n\n");
                    break;
                }
                int delete;
                printf("Enter email number to delete: ");
                scanf("%d", &delete);
                if (delete > count || delete < 1) {
                    printf("Invalid email number!\n\n");
                    break;
                }
                for (int i = delete-1; i < count-1; i++) {
                    strcpy(inbox[i].sender, inbox[i+1].sender);
                    strcpy(inbox[i].recipient, inbox[i+1].recipient);
                    strcpy(inbox[i].subject, inbox[i+1].subject);
                    strcpy(inbox[i].message, inbox[i+1].message);
                }
                count--;
                printf("Email %d deleted!\n\n", delete);
                break;

            case 4:
                printf("*** Thank you for using the Future Email Client! ***\n");
                return 0;
            
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
}