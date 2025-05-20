//FormAI DATASET v1.0 Category: Database querying ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000 

typedef struct {
    char id[10];
    char name[50];
    char address[100];
} Record;

int main() {
    // initialize database
    Record database[MAX_RECORDS];
    int num_records = 0;
    
    // read in database from file
    FILE *fp = fopen("database.txt", "r");
    if(fp == NULL) {
        printf("Error: database file could not be opened.\n");
        return 1;
    }
    while(fscanf(fp, "%s %s %s", database[num_records].id, database[num_records].name, database[num_records].address) != EOF) {
        num_records++;
    }
    fclose(fp);
    
    // sanitize user input
    char user_input[100];
    printf("Enter a name to search for: ");
    fgets(user_input, 100, stdin);
    user_input[strcspn(user_input, "\n")] = '\0'; // remove newline character
    
    // sanitize search query
    char query[150];
    sprintf(query, "SELECT * FROM database WHERE name='%s'", user_input);
    for(int i = 0; i < strlen(user_input); i++) {
        if(user_input[i] == ';' || user_input[i] == '\0' || user_input[i] == '\'') {
            printf("Error: invalid input detected.\n");
            return 1;
        }
    }
    
    // perform database query
    printf("Results:\n");
    for(int i = 0; i < num_records; i++) {
        if(strcmp(database[i].name, user_input) == 0) {
            printf("%s %s %s\n", database[i].id, database[i].name, database[i].address);
        }
    }
    
    // clear database from memory
    memset(database, 0, sizeof(database));
    
    return 0;
}