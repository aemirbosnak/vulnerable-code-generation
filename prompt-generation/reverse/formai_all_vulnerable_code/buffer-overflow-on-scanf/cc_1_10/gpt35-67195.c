//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include<stdio.h>
#include<string.h>
#define MAX 100 //The maximum number of emails that can be added to the list

struct MailingList {
    char name[50];
    char email[50];
    char phone_no[20];
};

void display_menu() {
    printf("Please select an option:\n");
    printf("1. Add email to mailing list\n");
    printf("2. Remove email from mailing list\n");
    printf("3. Display all emails in the mailing list\n");
    printf("4. Exit\n");
}

int add_email(struct MailingList list[], int count) {
    printf("Enter the name:\n");
    scanf("%s", list[count].name);
    printf("Enter the email:\n");
    scanf("%s", list[count].email);
    printf("Enter the phone number:\n");
    scanf("%s", list[count].phone_no);
    count++;
    return count;
}

int remove_email(struct MailingList list[], int count) {
    char email[50];
    printf("Enter the email to be removed:\n");
    scanf("%s", email);
    int i;
    for(i=0;i<count;i++) {
        if(strcmp(list[i].email,email) == 0) {
            int j;
            for(j=i;j<count-1;j++) {
                strcpy(list[j].name,list[j+1].name);
                strcpy(list[j].email,list[j+1].email);
                strcpy(list[j].phone_no,list[j+1].phone_no);
            }
            count--;
            printf("Email removed successfully.\n");
            return count;
        }
    }
    printf("Email not found in the mailing list.\n");
    return count;
}

void display_emails(struct MailingList list[], int count) {
    printf("Name\t\tEmail\t\tPhone No.\n");
    int i;
    for(i=0;i<count;i++) {
        printf("%s\t\t%s\t\t%s\n", list[i].name, list[i].email, list[i].phone_no);
    }
}

int main() {
    struct MailingList list[MAX];
    int count = 0;
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                count = add_email(list, count);
                break;
            case 2:
                count = remove_email(list, count);
                break;
            case 3:
                display_emails(list, count);
                break;
            case 4:
                printf("Thank you for using the mailing list manager.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}