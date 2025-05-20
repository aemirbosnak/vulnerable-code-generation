//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store a person's details
struct person {
    char name[50];
    char address[100];
    int phoneNumber;
};

// Define an array to store all the people
struct person people[10];

// Function to read the phone book from a file
void readPhoneBook(char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Read the file line by line
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // Tokenize the line into name, address, and phone number
        char *name = strtok(line, " ");
        char *address = strtok(NULL, " ");
        int phoneNumber = atoi(strtok(NULL, "\n"));

        // Create a new person struct and fill it with the details
        struct person p = {
            .name = name,
            .address = address,
            .phoneNumber = phoneNumber
        };

        // Add the person to the array
        people[sizeof(people) - 1] = p;
    }

    // Close the file
    fclose(file);
}

// Function to print the phone book
void printPhoneBook() {
    printf("Phone Book:\n");

    // Loop through the array of people and print their details
    for (int i = 0; i < sizeof(people); i++) {
        printf("Name: %s\nAddress: %s\nPhone Number: %d\n",
            people[i].name, people[i].address, people[i].phoneNumber);
    }
}

int main() {
    // Read the phone book from a file
    readPhoneBook("phone_book.txt");

    // Print the phone book
    printPhoneBook();

    return 0;
}