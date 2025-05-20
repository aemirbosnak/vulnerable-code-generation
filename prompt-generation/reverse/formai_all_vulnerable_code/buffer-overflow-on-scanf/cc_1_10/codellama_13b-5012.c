//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Database {
        int id;
        char name[50];
        char email[50];
        char password[50];
    };

    int main() {
        struct Database db;

        // Initialize database
        db.id = 0;
        strcpy(db.name, "");
        strcpy(db.email, "");
        strcpy(db.password, "");

        // Read input from user
        printf("Enter name: ");
        scanf("%s", db.name);
        printf("Enter email: ");
        scanf("%s", db.email);
        printf("Enter password: ");
        scanf("%s", db.password);

        // Write data to database
        FILE *fp = fopen("database.txt", "w");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fprintf(fp, "%d\n%s\n%s\n%s\n", db.id, db.name, db.email, db.password);
        fclose(fp);

        // Read data from database
        fp = fopen("database.txt", "r");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        fscanf(fp, "%d\n%s\n%s\n%s\n", &db.id, db.name, db.email, db.password);
        fclose(fp);

        // Print data
        printf("Name: %s\n", db.name);
        printf("Email: %s\n", db.email);
        printf("Password: %s\n", db.password);

        return 0;
    }