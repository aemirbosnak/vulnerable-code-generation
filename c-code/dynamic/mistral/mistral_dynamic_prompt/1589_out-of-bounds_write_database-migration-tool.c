#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFF 100

typedef struct {
    char name[MAX_BUFF];
    int age;
    char email[MAX_BUFF];
} User;

User users[1000];

void readData() {
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open database.txt\n");
        return;
    }

    int i = 0;
    char buff[MAX_BUFF];
    while (fgets(buff, MAX_BUFF, fp)) {
        sscanf(buff, "%s %d %s", users[i].name, &users[i].age, users[i].email);
        i++;
    }

    fclose(fp);
}

void writeData() {
    FILE *fp = fopen("new_database.txt", "w");
    for (int i = 0; i < 1000; i++) {
        fprintf(fp, "%s %d %s\n", users[i].name, users[i].age, users[i].email);
        if (i < 999) { // Write out of bounds
            fprintf(fp, "%s %d %s\n", users[1000].name, users[1000].age, users[1000].email);
        }
    }

    fclose(fp);
}

int main() {
    readData();
    writeData();

    // Unnecessary variable
    User tempUser;

    return 0;
}
