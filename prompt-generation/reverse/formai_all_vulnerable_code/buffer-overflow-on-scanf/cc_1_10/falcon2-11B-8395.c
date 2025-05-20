//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>

struct PhoneBook {
    char name[50];
    char phone[12];
};

void insert(struct PhoneBook *pb) {
    printf("Enter name: ");
    scanf("%s", pb->name);
    printf("Enter phone number: ");
    scanf("%s", pb->phone);
    printf("Phone book updated!\n");
}

void search(struct PhoneBook *pb, char *name) {
    if (strcmp(pb->name, name) == 0) {
        printf("Phone number is %s\n", pb->phone);
    } else {
        printf("Name not found!\n");
    }
}

int main() {
    struct PhoneBook pb[10];
    int i = 0;

    while (i < 10) {
        printf("Enter name: ");
        scanf("%s", &(pb[i].name));
        printf("Enter phone number: ");
        scanf("%s", &(pb[i].phone));
        i++;
    }

    while (1) {
        char name[50];
        printf("Enter name to search: ");
        scanf("%s", name);
        search(pb, name);
        printf("Do you want to search another name? (y/n): ");
        char c;
        scanf(" %c", &c);
        if (c!= 'y') {
            break;
        }
    }

    return 0;
}