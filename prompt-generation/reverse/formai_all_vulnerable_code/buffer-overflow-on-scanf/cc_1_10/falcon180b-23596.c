//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct student {
    int roll_no;
    char name[50];
    int age;
};

int search(struct student arr[], int n, int roll_no) {
    int i;
    for(i=0;i<n;i++) {
        if(arr[i].roll_no == roll_no) {
            return i;
        }
    }
    return -1;
}

void main() {
    int n,i,ch,roll_no;
    struct student arr[MAX];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    printf("Enter the details of students:\n");
    for(i=0;i<n;i++) {
        printf("Enter the roll number: ");
        scanf("%d",&arr[i].roll_no);
        printf("Enter the name: ");
        scanf("%s",arr[i].name);
        printf("Enter the age: ");
        scanf("%d",&arr[i].age);
    }
    while(1) {
        printf("\nEnter the roll number to search: ");
        scanf("%d",&roll_no);
        ch = search(arr,n,roll_no);
        if(ch == -1) {
            printf("\nStudent not found!\n");
        }
        else {
            printf("\nName: %s\nAge: %d\n",arr[ch].name,arr[ch].age);
        }
        printf("\nDo you want to continue? (y/n): ");
        char c;
        scanf(" %c",&c);
        if(c == 'n') {
            break;
        }
    }
}