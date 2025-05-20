//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personal_info {
    char name[30];
    int age;
    char email[30];
};

struct experience {
    char company[50];
    char designation[50];
    int duration;
};

struct resume {
    struct personal_info pInfo;
    struct experience exp[10];
};

int main() {
    struct resume res;
    char temp[30];

    printf("Enter your name: ");
    fgets(temp, 30, stdin);
    sscanf(temp, "%[^\n]", res.pInfo.name);

    printf("Enter your age: ");
    fgets(temp, 30, stdin);
    sscanf(temp, "%d", &res.pInfo.age);

    printf("Enter your email address: ");
    fgets(temp, 30, stdin);
    sscanf(temp, "%[^\n]", res.pInfo.email);

    printf("Enter details of your work experience in the following format: Company, Designation, Duration (in months)\n");
    for(int i = 0; i < 10; i++) {
        printf("Enter details of experience %d: ", i+1);
        fgets(temp, 50, stdin);
        sscanf(temp, "%[^,], %[^\n], %d", res.exp[i].company, res.exp[i].designation, &res.exp[i].duration);
    }

    printf("\n\nResume Preview");

    printf("\n\nName: %s", res.pInfo.name);
    printf("Age: %d\n", res.pInfo.age);
    printf("Email: %s\n", res.pInfo.email);

    printf("\nWork Experience:\n");
    for(int i = 0; i < 10; i++) {
        if(strlen(res.exp[i].company) > 0){
            printf("%d) %s\nDesignation: %s\nDuration: %d months\n", i+1, res.exp[i].company, res.exp[i].designation, res.exp[i].duration);
        }
    }

    printf("\n\nResume Parsing Complete!");
    return 0;
}