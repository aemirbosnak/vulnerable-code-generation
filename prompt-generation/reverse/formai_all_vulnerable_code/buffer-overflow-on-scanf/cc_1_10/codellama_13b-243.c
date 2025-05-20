//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: Cryptic
// A cryptic C database querying example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_FILE "mydb.dat"
#define DB_SIZE 10000

struct record {
    int id;
    char name[20];
    char email[30];
    char phone[15];
};

int main() {
    struct record db[DB_SIZE];
    FILE *fp;
    int i, id, count = 0;
    char name[20], email[30], phone[15];

    fp = fopen(DB_FILE, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", DB_FILE);
        return 1;
    }

    while (fread(&db[count], sizeof(struct record), 1, fp) == 1) {
        count++;
    }

    printf("Enter id: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (db[i].id == id) {
            strcpy(name, db[i].name);
            strcpy(email, db[i].email);
            strcpy(phone, db[i].phone);
            break;
        }
    }

    if (i == count) {
        printf("Record not found\n");
        return 1;
    }

    printf("Name: %s\nEmail: %s\nPhone: %s\n", name, email, phone);

    fclose(fp);
    return 0;
}