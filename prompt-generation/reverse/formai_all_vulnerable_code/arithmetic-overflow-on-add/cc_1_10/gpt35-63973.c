//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    int age;
    float marks;
};

void insert(struct student* s, int n) {
    printf("\nEnter details of %d student:\n", n+1);
    printf("\nEnter ID : ");
    scanf("%d", &(s+n)->id);
    printf("\nEnter name : ");
    scanf("%s", (s+n)->name);
    printf("\nEnter age : ");
    scanf("%d", &(s+n)->age);
    printf("\nEnter marks : ");
    scanf("%f", &(s+n)->marks);
}

void search(struct student* s, int id, int n) {
    int i, flag = 0;
    for(i=0; i<n; i++) {
        if((s+i)->id == id) {
            printf("\nDetails of student are : ");
            printf("\nID : %d", (s+i)->id);
            printf("\nName : %s", (s+i)->name);
            printf("\nAge : %d", (s+i)->age);
            printf("\nMarks : %.2f\n", (s+i)->marks);
            flag = 1;
            break;
        }
    }
    if(!flag) {
        printf("\nNo such student found.\n");
    }
}

void display(struct student* s, int n) {
    int i;
    printf("\nDetails of all students:\n");
    for(i=0; i<n; i++) {
        printf("\nDetails of student %d : ", i+1);
        printf("\nID : %d", (s+i)->id);
        printf("\nName : %s", (s+i)->name);
        printf("\nAge : %d", (s+i)->age);
        printf("\nMarks : %.2f\n", (s+i)->marks);
    }
}

int main() {
    int n, ch, id;
    struct student *s;
    printf("Enter number of students : ");
    scanf("%d", &n);
    s = (struct student*)malloc(n*sizeof(struct student));
    while(1) {
        printf("\nMenu :\n1.Insert Details\n2.Search a student\n3.Display all\n4.Exit\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                if(n==0) {
                    s = (struct student*)malloc(sizeof(struct student));
                } else {
                    s = (struct student*)realloc(s,(n+1)*sizeof(struct student));
                }
                insert(s, n);
                n++;
                break;
            case 2:
                printf("\nEnter ID to be searched : ");
                scanf("%d", &id);
                search(s,id,n);
                break;
            case 3:
                display(s,n);
                break;
            case 4:
                free(s);
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}