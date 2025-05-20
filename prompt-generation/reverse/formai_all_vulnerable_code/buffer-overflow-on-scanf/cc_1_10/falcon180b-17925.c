//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student {
    char name[50];
    int roll_no;
    int marks[5];
};

void add_student(struct student *s) {
    int i;
    printf("Enter student name: ");
    scanf("%s", s->name);
    printf("Enter student roll number: ");
    scanf("%d", &s->roll_no);

    for(i=0; i<5; i++) {
        printf("Enter marks for subject %d: ", i+1);
        scanf("%d", &s->marks[i]);
    }
}

void display_student(struct student s) {
    int i;
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll_no);

    for(i=0; i<5; i++) {
        printf("Marks for subject %d: %d\n", i+1, s.marks[i]);
    }
}

int main() {
    struct student s[10];
    int choice, i;

    for(i=0; i<10; i++) {
        add_student(&s[i]);
    }

    while(1) {
        printf("\n1. Display all students\n2. Search student by name\n3. Search student by roll number\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i=0; i<10; i++) {
                    display_student(s[i]);
                }
                break;
            case 2:
                printf("Enter student name to search: ");
                char name[50];
                scanf("%s", name);
                for(i=0; i<10; i++) {
                    if(strcmp(s[i].name, name) == 0) {
                        display_student(s[i]);
                    }
                }
                break;
            case 3:
                printf("Enter student roll number to search: ");
                int roll_no;
                scanf("%d", &roll_no);
                for(i=0; i<10; i++) {
                    if(s[i].roll_no == roll_no) {
                        display_student(s[i]);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}