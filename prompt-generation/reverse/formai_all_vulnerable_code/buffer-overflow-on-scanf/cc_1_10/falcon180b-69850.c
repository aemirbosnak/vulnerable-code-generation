//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define size 100

struct diary {
    char title[size];
    char entry[500];
    time_t date;
};

void addEntry(struct diary *d) {
    printf("Enter the title: ");
    scanf("%s", d->title);
    printf("Enter the entry: ");
    scanf("%s", d->entry);
    time(&d->date);
}

void viewEntry(struct diary *d) {
    printf("Title: %s\n", d->title);
    printf("Entry: %s\n", d->entry);
    printf("Date: %s", ctime(&d->date));
}

void searchEntry(struct diary *d, int n, char keyword[size]) {
    int i = 0;
    while(i < n) {
        if(strcmp(d[i].title, keyword) == 0 || strcmp(d[i].entry, keyword) == 0) {
            viewEntry(&d[i]);
        }
        i++;
    }
}

int main() {
    struct diary d[10];
    int n = 0;

    while(1) {
        printf("1. Add entry\n2. View all entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(n == 10) {
                    printf("Diary is full.\n");
                } else {
                    addEntry(&d[n]);
                    n++;
                }
                break;
            case 2:
                for(int i = 0; i < n; i++) {
                    viewEntry(&d[i]);
                }
                break;
            case 3:
                printf("Enter the keyword to search: ");
                scanf("%s", d[n-1].title);
                searchEntry(d, n, d[n-1].title);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}