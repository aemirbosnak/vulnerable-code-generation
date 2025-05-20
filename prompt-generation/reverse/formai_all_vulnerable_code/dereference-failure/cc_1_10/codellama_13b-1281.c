//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: paranoid
// A paranoid C database querying example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define a database structure
struct Database {
    char name[100];
    int age;
};

int main() {
    // Define a database instance
    struct Database database;

    // Initialize the database
    memset(&database, 0, sizeof(database));

    // Set the database name
    strcpy(database.name, "John");

    // Set the database age
    database.age = 30;

    // Open the database file
    FILE *file = fopen("database.bin", "wb");
    if (file == NULL) {
        printf("Error opening database file: %s\n", strerror(errno));
        return 1;
    }

    // Write the database to the file
    if (fwrite(&database, sizeof(database), 1, file) != 1) {
        printf("Error writing to database file: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    // Close the database file
    fclose(file);

    // Open the database file again
    file = fopen("database.bin", "rb");
    if (file == NULL) {
        printf("Error opening database file: %s\n", strerror(errno));
        return 1;
    }

    // Read the database from the file
    if (fread(&database, sizeof(database), 1, file) != 1) {
        printf("Error reading from database file: %s\n", strerror(errno));
        fclose(file);
        return 1;
    }

    // Print the database information
    printf("Name: %s\n", database.name);
    printf("Age: %d\n", database.age);

    // Close the database file
    fclose(file);

    return 0;
}