//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_LISTS 10
#define MAX_MEMBERS 100

struct Email {
    char address[MAX_EMAIL_LENGTH];
};

struct Person {
    char name[MAX_NAME_LENGTH];
    struct Email email;
};

struct MailingList {
    char name[MAX_NAME_LENGTH];
    struct Person members[MAX_MEMBERS];
    int numMembers;
};

int main() {
    struct MailingList lists[MAX_LISTS]; // array to hold mailing lists
    int numLists = 0; // number of mailing lists currently in use

    printf("Greetings. I am the Mailing List Manager.\n");
    printf("What would you like to do?\n");

    while (1) {
        printf("Options:\n");
        printf("1. Create a new mailing list.\n");
        printf("2. Add a member to a mailing list.\n");
        printf("3. Remove a member from a mailing list.\n");
        printf("4. Print all mailing lists.\n");
        printf("5. Quit.\n");

        int option;
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: { // create a new mailing list 
                printf("What would you like to name the new mailing list?\n");
                char listName[MAX_NAME_LENGTH];
                scanf("%s", listName);

                struct MailingList newList;
                strcpy(newList.name, listName); 
                newList.numMembers = 0; // initialize number of members to zero

                lists[numLists] = newList; // add to the end of the list
                numLists++;

                printf("The %s mailing list has been created.\n", listName);

                break;
            }
            case 2: { // add a member to a mailing list
                printf("Which mailing list would you like to add a member to?\n");
                char listName[MAX_NAME_LENGTH];
                scanf("%s", listName);

                struct MailingList* list = NULL;
                for (int i = 0; i < numLists; i++) {
                    if (strcmp(lists[i].name, listName) == 0) {
                        list = &lists[i];
                        break;
                    }
                }

                if (list != NULL) {
                    if (list->numMembers >= MAX_MEMBERS) {
                        printf("Sorry, this mailing list is at capacity.\n");
                    } else {
                        printf("What is the name of the new member?\n");
                        char memberName[MAX_NAME_LENGTH];
                        scanf("%s", memberName);

                        printf("What is the email address of the new member?\n");
                        char email[MAX_EMAIL_LENGTH];
                        scanf("%s", email);

                        struct Person newMember;
                        strcpy(newMember.name, memberName);
                        strcpy(newMember.email.address, email);
                        
                        list->members[list->numMembers] = newMember;
                        list->numMembers++;

                        printf("%s has been added to the %s mailing list.\n", memberName, list->name);
                    }
                } else {
                    printf("Sorry, the %s mailing list does not exist.\n", listName);
                }

                break;
            }
            case 3: { // remove a member from a mailing list
                printf("Which mailing list would you like to remove a member from?\n");
                char listName[MAX_NAME_LENGTH];
                scanf("%s", listName);

                struct MailingList* list = NULL;
                for (int i = 0; i < numLists; i++) {
                    if (strcmp(lists[i].name, listName) == 0) {
                        list = &lists[i];
                        break;
                    }
                }

                if (list != NULL) {
                    printf("Which member would you like to remove?\n");
                    char memberName[MAX_NAME_LENGTH];
                    scanf("%s", memberName);

                    int indexToRemove = -1;
                    for (int i = 0; i < list->numMembers; i++) {
                        if (strcmp(list->members[i].name, memberName) == 0) {
                            indexToRemove = i;
                            break;
                        }
                    }

                    if (indexToRemove == -1) {
                        printf("Sorry, %s is not a member of the %s mailing list.\n", memberName, list->name);
                    } else {
                        for (int i = indexToRemove; i < list->numMembers - 1; i++) {
                            list->members[i] = list->members[i+1]; // shift other members left
                        }
                        list->numMembers--;

                        printf("%s has been removed from the %s mailing list.\n", memberName, list->name);
                    }
                } else {
                    printf("Sorry, the %s mailing list does not exist.\n", listName);
                }

                break;
            }
            case 4: { // print all mailing lists
                if (numLists == 0) {
                    printf("There are no mailing lists to display.\n");
                } else {
                    printf("Mailing lists:\n");
                    for (int i = 0; i < numLists; i++) {
                        printf("%s (%d members):\n", lists[i].name, lists[i].numMembers);
                        if (lists[i].numMembers == 0) {
                            printf("  This mailing list has no members.\n");
                        } else {
                            for (int j = 0; j < lists[i].numMembers; j++) {
                                printf("  %s <%s>\n", lists[i].members[j].name, lists[i].members[j].email.address);
                            }
                        }
                    }
                }

                break;
            }
            case 5: { // quit
                printf("Farewell. Exiting the Mailing List Manager.\n");
                return 0;
            }
            default: {
                printf("Sorry, that is not a valid option.\n");

                break;
            }
        }
    }
}