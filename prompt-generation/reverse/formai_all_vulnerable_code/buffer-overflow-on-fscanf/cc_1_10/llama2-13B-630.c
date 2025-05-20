//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
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
        perror("Error opening file");
        return user;
    }
    fscanf(file, "%s %d", user.name, &user.age);
    fclose(file);
    return user;
}

// Function to write user information to file
void write_user_info(const char* file_name, user_info user) {
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s %d\n", user.name, user.age);
    fclose(file);
}

int main() {
    // Read user information from file
    user_info user = read_user_info("user_info.txt");
    printf("User information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);

    // Modify user information
    user.age += 5;
    printf("Modified user information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);

    // Write modified user information to file
    write_user_info("user_info_modified.txt", user);

    return 0;
}