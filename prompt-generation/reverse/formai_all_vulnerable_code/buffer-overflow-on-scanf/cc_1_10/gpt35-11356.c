//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void display_menu();
void read_email();
void send_email();
void delete_email();
void view_inbox();

int main() {
    display_menu();
    return 0;
}

void display_menu() {
    int option;

    printf("Welcome to C Email Client\n");
    printf("1. Read Email\n");
    printf("2. Send Email\n");
    printf("3. Delete Email\n");
    printf("4. View Inbox\n");
    printf("5. Exit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            read_email();
            break;
        case 2:
            send_email();
            break;
        case 3:
            delete_email();
            break;
        case 4:
            view_inbox();
            break;
        case 5:
            printf("Thank you for using C Email Client\n");
            exit(0);
        default:
            printf("Invalid option selected\n");
            break;
    }
}

void read_email() {
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    FILE *file;

    printf("Enter the name of the email file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (!file) {
        printf("Error opening file '%s'\n", filename);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void send_email() {
    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    FILE *file;

    printf("Enter the name of the email file to send: ");
    scanf("%s", filename);

    file = fopen(filename, "w");

    if (!file) {
        printf("Error opening file '%s'\n", filename);
        return;
    }

    printf("Enter your email message (press Ctrl-D to end):\n");

    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        fputs(buffer, file);
    }

    fclose(file);
}

void delete_email() {
    char filename[BUFFER_SIZE];

    printf("Enter the name of the email file to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("Email file '%s' deleted successfully\n", filename);
    } else {
        printf("Error deleting file '%s'\n", filename);
    }
}

void view_inbox() {
    system("ls *.txt");
}