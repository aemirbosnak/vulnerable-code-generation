//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_ADDR_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char addr[MAX_ADDR_LEN];
} contact;

contact *create_contact(char *name, char *addr) {
    contact *c = (contact *)malloc(sizeof(contact));
    strcpy(c->name, name);
    strcpy(c->addr, addr);
    return c;
}

void print_contact(contact *c) {
    printf("Name: %s\nAddress: %s\n", c->name, c->addr);
}

int compare_contacts(contact *c1, contact *c2) {
    return strcmp(c1->name, c2->name);
}

void sort_contacts(contact *contacts, int n) {
    qsort(contacts, n, sizeof(contact), compare_contacts);
}

int main() {
    FILE *f;
    contact *contacts = NULL;
    int n = 0;

    f = fopen("contacts.txt", "r");
    if (f == NULL) {
        printf("Error: Unable to open contacts file.\n");
        exit(1);
    }

    while (fscanf(f, "%s %s", contacts[n].name, contacts[n].addr)!= EOF) {
        n++;
    }

    fclose(f);

    qsort(contacts, n, sizeof(contact), compare_contacts);

    for (int i = 0; i < n; i++) {
        print_contact(&contacts[i]);
    }

    return 0;
}