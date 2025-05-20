#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char email[50];
    int id;
} User;

int main() {
    User users[1000];

    for (int i = 0; i < 1000; i++) {
        sprintf(users[i].name, "User%d", i);
        users[i].email[0] = 'u';
        users[i].email[1] = 's';
        users[i].email[2] = 'e';
        users[i].email[3] = 'r';
        for (int j = 4; j < 50; j++)
            users[i].email[j] = '0';
        users[i].id = i * 1000;
    }

    FILE *db = fopen("db.dat", "wb");
    fwrite(users, sizeof(User), 1000, db);
    fclose(db);

    return 0;
}
