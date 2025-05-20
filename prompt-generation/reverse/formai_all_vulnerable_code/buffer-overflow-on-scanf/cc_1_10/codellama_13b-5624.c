//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to store data
struct data {
    char name[100];
    int age;
    char email[100];
};

// Function to check if a name is unique
bool is_unique_name(char* name, struct data* data_arr, int num_data) {
    for (int i = 0; i < num_data; i++) {
        if (strcmp(name, data_arr[i].name) == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if an email is unique
bool is_unique_email(char* email, struct data* data_arr, int num_data) {
    for (int i = 0; i < num_data; i++) {
        if (strcmp(email, data_arr[i].email) == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if a name and email combination is unique
bool is_unique_name_email(char* name, char* email, struct data* data_arr, int num_data) {
    for (int i = 0; i < num_data; i++) {
        if (strcmp(name, data_arr[i].name) == 0 && strcmp(email, data_arr[i].email) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // Array of structs to store data
    struct data data_arr[100];
    int num_data = 0;

    // Prompt user for input
    printf("Enter name, age, and email:\n");
    while (num_data < 100) {
        // Read input
        scanf("%s %d %s", data_arr[num_data].name, &data_arr[num_data].age, data_arr[num_data].email);

        // Check if name is unique
        if (!is_unique_name(data_arr[num_data].name, data_arr, num_data)) {
            printf("Name already exists. Please enter a different name.\n");
            continue;
        }

        // Check if email is unique
        if (!is_unique_email(data_arr[num_data].email, data_arr, num_data)) {
            printf("Email already exists. Please enter a different email.\n");
            continue;
        }

        // Check if name and email combination is unique
        if (!is_unique_name_email(data_arr[num_data].name, data_arr[num_data].email, data_arr, num_data)) {
            printf("Name and email combination already exists. Please enter a different name and email.\n");
            continue;
        }

        // Increment number of data entered
        num_data++;
    }

    // Print data
    for (int i = 0; i < num_data; i++) {
        printf("%s, %d, %s\n", data_arr[i].name, data_arr[i].age, data_arr[i].email);
    }

    return 0;
}