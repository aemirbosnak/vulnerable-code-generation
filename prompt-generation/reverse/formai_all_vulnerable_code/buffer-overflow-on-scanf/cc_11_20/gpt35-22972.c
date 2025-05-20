//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define SIZE 10

struct contact {
    char name[20];
    char phone[11];
};

int main() {
    struct contact phonebook[SIZE];

    int count = 0;
    int choice;
    int i, found;

    do {
        printf("\nPhonebook Menu\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count < SIZE) {
                    printf("\nAdd Contact\n");

                    printf("Enter Name: ");
                    scanf("%s", phonebook[count].name);

                    printf("Enter Phone Number: ");
                    scanf("%s", phonebook[count].phone);

                    count++;

                    printf("\nContact added successfully!\n");
                } else {
                    printf("\nPhonebook is full!\n");
                }
                break;

            case 2:
                if(count > 0) {
                    char name[20];

                    printf("\nRemove Contact\n");

                    printf("Enter name: ");
                    scanf("%s", name);

                    found = 0;

                    for(i = 0; i < count; i++) {
                        if(strcmp(name, phonebook[i].name) == 0) {
                            found = 1;
                            break;
                        }
                    }

                    if(found) {
                        for(; i < count - 1; i++) {
                            strcpy(phonebook[i].name, phonebook[i+1].name);
                            strcpy(phonebook[i].phone, phonebook[i+1].phone);
                        }

                        count--;

                        printf("\nContact removed successfully!\n");
                    } else {
                        printf("\nContact not found!\n");
                    }
                } else {
                    printf("\nPhonebook is empty!\n");
                }
                break;

            case 3:
                if(count > 0) {
                    char name[20];

                    printf("\nSearch Contact\n");

                    printf("Enter name: ");
                    scanf("%s", name);

                    found = 0;

                    for(i = 0; i < count; i++) {
                        if(strcmp(name, phonebook[i].name) == 0) {
                            found = 1;

                            printf("\n- Name: %s\n", phonebook[i].name);
                            printf("- Phone Number: %s\n", phonebook[i].phone);

                            break;
                        }
                    }

                    if(!found) {
                        printf("\nContact not found!\n");
                    }
                } else {
                    printf("\nPhonebook is empty!\n");
                }
                break;

            case 4:
                if(count > 0) {
                    printf("\nDisplay All Contacts\n");

                    for(i = 0; i < count; i++) {
                        printf("\n- Name: %s\n", phonebook[i].name);
                        printf("- Phone Number: %s\n", phonebook[i].phone);
                    }
                } else {
                    printf("\nPhonebook is empty!\n");
                }
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}