//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct education {
    char degree[50];
    char field[50];
    char university[50];
    int year;
};

struct experience {
    char company[50];
    char position[50];
    int start_year;
    int end_year;
};

struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char location[50];
    struct education ed[5];
    struct experience exp[10];
};

int main() {
    struct resume r;
    printf("Please enter your full name: ");
    gets(r.name);
    printf("Please enter your email address: ");
    gets(r.email);
    printf("Please enter your phone number: ");
    gets(r.phone);
    printf("Please enter your location: ");
    gets(r.location);
    printf("Please enter your educational information:\n");
    for(int i=0; i<5; i++) {
        printf("Degree: ");
        gets(r.ed[i].degree);
        printf("Field of study: ");
        gets(r.ed[i].field);
        printf("University: ");
        gets(r.ed[i].university);
        printf("Year of graduation: ");
        scanf("%d", &r.ed[i].year);
        getchar();
    }
    printf("Please enter your work experience information:\n");
    for(int i=0; i<10; i++) {
        printf("Company: ");
        gets(r.exp[i].company);
        printf("Position: ");
        gets(r.exp[i].position);
        printf("Start year: ");
        scanf("%d", &r.exp[i].start_year);
        printf("End year (0 if still working there): ");
        scanf("%d", &r.exp[i].end_year);
        getchar();
    }
    // Printing the parsed resume
    printf("\n\nName: %s\nEmail: %s\nPhone: %s\nLocation: %s\n", r.name, r.email, r.phone, r.location);
    printf("\nEducation:\n");
    for(int i=0; i<5; i++) {
        printf("%d)\n", i+1);
        printf("   Degree: %s\n", r.ed[i].degree);
        printf("   Field of study: %s\n", r.ed[i].field);
        printf("   University: %s\n", r.ed[i].university);
        printf("   Year of graduation: %d\n", r.ed[i].year);
    }
    printf("\nWork experience:\n");
    for(int i=0; i<10; i++) {
        if(strcmp(r.exp[i].company, "") != 0) {
            printf("%d)\n", i+1);
            printf("   Company: %s\n", r.exp[i].company);
            printf("   Position: %s\n", r.exp[i].position);
            printf("   Start year: %d\n", r.exp[i].start_year);
            printf("   End year: ");
            if(r.exp[i].end_year == 0) printf("Still working there\n");
            else printf("%d\n", r.exp[i].end_year);
        }
    }
    return 0;
}