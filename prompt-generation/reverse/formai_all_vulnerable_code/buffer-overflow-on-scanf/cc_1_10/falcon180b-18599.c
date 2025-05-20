//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

struct resume{
    char name[MAX];
    char address[MAX];
    char email[MAX];
    char phone[MAX];
    char education[MAX];
    char experience[MAX];
};

void getResume(struct resume* r){
    printf("Enter Name: ");
    scanf("%[^\n]",r->name);
    getchar();

    printf("Enter Address: ");
    scanf("%[^\n]",r->address);
    getchar();

    printf("Enter Email: ");
    scanf("%[^\n]",r->email);
    getchar();

    printf("Enter Phone: ");
    scanf("%[^\n]",r->phone);
    getchar();

    printf("Enter Education: ");
    scanf("%[^\n]",r->education);
    getchar();

    printf("Enter Experience: ");
    scanf("%[^\n]",r->experience);
    getchar();
}

void displayResume(struct resume* r){
    printf("Name: %s\n",r->name);
    printf("Address: %s\n",r->address);
    printf("Email: %s\n",r->email);
    printf("Phone: %s\n",r->phone);
    printf("Education: %s\n",r->education);
    printf("Experience: %s\n",r->experience);
}

int main(){
    struct resume r;
    getResume(&r);
    displayResume(&r);
    return 0;
}