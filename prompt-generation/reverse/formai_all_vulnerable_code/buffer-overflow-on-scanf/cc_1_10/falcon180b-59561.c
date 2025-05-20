//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_LENGTH 100

typedef struct {
    char email[MAX_LENGTH];
    char name[MAX_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* email, char* name) {
    strcpy(emails[num_emails].email, email);
    strcpy(emails[num_emails].name, name);
    num_emails++;
}

void print_emails() {
    int i;
    for(i=0; i<num_emails; i++) {
        printf("%s: %s\n", emails[i].name, emails[i].email);
    }
}

void remove_email(char* email) {
    int i;
    for(i=0; i<num_emails; i++) {
        if(strcmp(emails[i].email, email) == 0) {
            num_emails--;
            memmove(&emails[i], &emails[i+1], sizeof(Email)*(num_emails-i-1));
            break;
        }
    }
}

int main() {
    char input[MAX_LENGTH];
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    int choice;

    do {
        printf("1. Add email\n2. Print emails\n3. Remove email\n4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_email(email, name);
            break;
        case 2:
            print_emails();
            break;
        case 3:
            printf("Enter email: ");
            scanf("%s", email);
            remove_email(email);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}