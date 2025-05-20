//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NAME_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

// Define a struct to hold the name and message of the sender
struct sender_info {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

// Function to read a file containing sender information
void read_sender_info(struct sender_info *sender, char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fscanf(file, "%s %s", sender->name, sender->message);
    fclose(file);
}

// Function to write the sender information to a file
void write_sender_info(struct sender_info *sender, char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s %s", sender->name, sender->message);
    fclose(file);
}

int main() {
    struct sender_info sender;
    char file_name[] = "sender_info.txt";

    // Read the sender information from the file
    read_sender_info(&sender, file_name);

    // Print the sender information
    printf("Sender Information:\n");
    printf("Name: %s\n", sender.name);
    printf("Message: %s\n", sender.message);

    // Allow the user to input a new message
    printf("Enter a new message: ");
    fgets(sender.message, MAX_MESSAGE_LENGTH, stdin);

    // Write the updated sender information to the file
    write_sender_info(&sender, file_name);

    return 0;
}