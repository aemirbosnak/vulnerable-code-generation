//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SENDER_NAME 50
#define MAX_RECIPIENT_NAME 50
#define MAX_SUBJECT 100
#define MAX_BODY 500
#define MAX_FOLDER_NAME 20


/* Structs */
typedef struct {
    char sender_name[MAX_SENDER_NAME];
    char recipient_name[MAX_RECIPIENT_NAME];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
} Email;

typedef struct {
    char name[MAX_FOLDER_NAME];
    int num_emails;
    Email emails[MAX_EMAILS];
} Folder;


/* Function declarations */
void create_email(Email *temp_email);
void print_email(Email *temp_email);
void create_folder(Folder *temp_folder);
void print_folder(Folder *temp_folder);
void add_email_to_folder(Email *temp_email, Folder *temp_folder);
void print_menu();
void print_folders(Folder *folders, int num_folders);
void print_emails_in_folder(Folder *temp_folder);


/* Main function */
int main() {
    Folder folders[MAX_EMAILS];
    int num_folders = 0;
    int folder_choice, email_choice;
    char name[MAX_FOLDER_NAME], choice;
    Email email;

    while (1) {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1': // Create email
                create_email(&email);
                printf("\nEmail created successfully.\n\n");
                break;

            case '2': // Print email
                print_email(&email);
                printf("\n");
                break;

            case '3': // Create folder
                create_folder(&folders[num_folders]);
                num_folders++;
                printf("\nFolder created successfully.\n\n");
                break;

            case '4': // Print all folders
                print_folders(folders, num_folders);
                break;

            case '5': // Select a folder
                print_folders(folders, num_folders);
                printf("Enter the number of the folder you would like to select: ");
                scanf("%d", &folder_choice);

                while (1) {
                    if (folder_choice >= 1 && folder_choice <= num_folders) {
                        while (1) {
                            print_emails_in_folder(&folders[folder_choice-1]);
                            printf("Enter the number of an email to view its contents or enter '0' to exit the folder: ");
                            scanf("%d", &email_choice);
                            if (email_choice >= 1 && email_choice <= folders[folder_choice-1].num_emails) {
                                printf("\nContents of email %d:\n", email_choice);
                                print_email(&folders[folder_choice-1].emails[email_choice-1]);
                                printf("\n");
                            } else if (email_choice == 0) {
                                printf("\nExited folder %d.\n\n", folder_choice);
                                break;
                            } else {
                                printf("\nInvalid email number. Please enter a number from 1 to %d, or enter 0 to exit the folder.\n\n", folders[folder_choice-1].num_emails);
                            }
                        }
                        break;
                    } else {
                        printf("\nInvalid folder number. Please enter a number from 1 to %d.\n\n", num_folders);
                        print_folders(folders, num_folders);
                        scanf("%d", &folder_choice);
                    }
                }
                break;

            case '6': // Add email to a folder
                if (num_folders == 0) {
                    printf("\nThere are no folders to add the email to. Please create a folder first.\n\n");
                    break;
                }

                print_folders(folders, num_folders);
                printf("\nWhich folder would you like to add the email to? Enter the number of the folder: ");
                scanf("%d", &folder_choice);

                while (1) {
                    if (folder_choice >= 1 && folder_choice <= num_folders) {
                        add_email_to_folder(&email, &folders[folder_choice-1]);
                        printf("\nEmail added to folder %d successfully.\n\n", folder_choice);
                        break;
                    } else {
                        printf("\nInvalid folder number. Please enter a number from 1 to %d.\n\n", num_folders);
                        print_folders(folders, num_folders);
                        scanf("%d", &folder_choice);
                    }
                }
                break;

            case '7': // Exit program
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please enter a number from 1 to 7.\n\n");
                break;
        }
    }

    return 0;
}


/* Function definitions */
void create_email(Email *temp_email) {
    printf("\nEnter sender's name: ");
    scanf(" %[^\n]s", temp_email->sender_name);
    printf("Enter recipient's name: ");
    scanf(" %[^\n]s", temp_email->recipient_name);
    printf("Enter subject: ");
    scanf(" %[^\n]s", temp_email->subject);
    printf("Enter body: ");
    scanf(" %[^\n]s", temp_email->body);
}

void print_email(Email *temp_email) {
    printf("\nFrom: %s\nTo: %s\nSubject: %s\n\n%s\n", temp_email->sender_name, temp_email->recipient_name, temp_email->subject, temp_email->body);
}

void create_folder(Folder *temp_folder) {
    printf("\nEnter folder name (up to %d characters): ", MAX_FOLDER_NAME);
    scanf(" %[^\n]s", temp_folder->name);
    temp_folder->num_emails = 0;
}

void print_folder(Folder *temp_folder) {
    printf("\n%s (%d emails)\n", temp_folder->name, temp_folder->num_emails);
}

void add_email_to_folder(Email *temp_email, Folder *temp_folder) {
    temp_folder->emails[temp_folder->num_emails] = *temp_email;
    temp_folder->num_emails++;
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Create email\n");
    printf("2. Print email\n");
    printf("3. Create folder\n");
    printf("4. Print all folders\n");
    printf("5. Select a folder\n");
    printf("6. Add email to a folder\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void print_folders(Folder *folders, int num_folders) {
    printf("\nFolders:\n");
    for (int i = 0; i < num_folders; i++) {
        printf("%d. ", i+1);
        print_folder(&folders[i]);
    }
    printf("\n");
}

void print_emails_in_folder(Folder *temp_folder) {
    printf("\nFolder: %s (%d emails)\n", temp_folder->name, temp_folder->num_emails);
    for (int i = 0; i < temp_folder->num_emails; i++) {
        printf("%d. %s\n", i+1, temp_folder->emails[i].subject);
    }
    printf("\n");
}