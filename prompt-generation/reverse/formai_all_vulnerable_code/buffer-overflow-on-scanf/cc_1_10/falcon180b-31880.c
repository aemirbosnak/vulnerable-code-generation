//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define MAX_RECIPIENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} recipient;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int num_recipients;
    recipient recipients[MAX_RECIPIENTS];
} mailing_list;

int main() {
    mailing_list list;
    int i, j, choice;

    printf("Welcome to the mailing list manager!\n");
    printf("Please choose an option:\n");
    printf("1. Add recipient\n");
    printf("2. Remove recipient\n");
    printf("3. Send message\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", list.recipients[0].name);
            printf("Enter email: ");
            scanf("%s", list.recipients[0].email);
            list.num_recipients = 1;
            break;
        case 2:
            printf("Enter name to remove: ");
            scanf("%s", list.recipients[0].name);
            for(i=0; i<list.num_recipients; i++) {
                if(strcmp(list.recipients[i].name, list.recipients[0].name) == 0) {
                    for(j=i; j<list.num_recipients-1; j++) {
                        strcpy(list.recipients[j].name, list.recipients[j+1].name);
                        strcpy(list.recipients[j].email, list.recipients[j+1].email);
                    }
                    list.num_recipients--;
                    break;
                }
            }
            break;
        case 3:
            printf("Enter subject: ");
            scanf("%s", list.subject);
            printf("Enter message: ");
            scanf("%s", list.message);
            for(i=0; i<list.num_recipients; i++) {
                printf("Sending message to %s...\n", list.recipients[i].name);
                // code to send email to recipient
            }
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}