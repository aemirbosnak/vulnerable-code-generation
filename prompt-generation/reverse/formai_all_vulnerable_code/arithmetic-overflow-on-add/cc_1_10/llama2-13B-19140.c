//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} user_info;

// Function to read user information from file
user_info read_user_info(const char* file_name) {
    user_info user;
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return user;
    }
    // Read name and age from file
    fscanf(file, "%s %d", user.name, &user.age);
    fclose(file);
    return user;
}

// Function to write user information to file
void write_user_info(const char* file_name, const user_info* user) {
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }
    // Write name and age to file
    fprintf(file, "%s %d", user->name, user->age);
    fclose(file);
}

int main() {
    // Read user information from file
    user_info user = read_user_info("user_info.txt");

    // Display user information
    printf("Name: %s\nAge: %d\n", user.name, user.age);

    // Modify user information
    user.age += 5;

    // Write modified user information to file
    write_user_info("user_info_modified.txt", &user);

    // Display modified user information
    printf("Name: %s\nAge: %d\n", user.name, user.age);

    return 0;
}