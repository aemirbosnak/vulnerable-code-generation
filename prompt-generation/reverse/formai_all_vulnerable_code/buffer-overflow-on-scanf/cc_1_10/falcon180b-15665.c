//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct resume {
    char name[40];
    char address[100];
    char email[50];
    char phone[15];
    char education[100];
    char experience[200];
};

void read_file(FILE *fp, struct resume *r) {
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i == 0) {
            strcpy(r->name, line);
        }
        else if (i == 1) {
            strcpy(r->address, line);
        }
        else if (i == 2) {
            strcpy(r->email, line);
        }
        else if (i == 3) {
            strcpy(r->phone, line);
        }
        else if (i == 4) {
            strcpy(r->education, line);
        }
        else if (i == 5) {
            strcpy(r->experience, line);
        }
        i++;
    }
}

void print_resume(struct resume r) {
    printf("Name: %s\n", r.name);
    printf("Address: %s\n", r.address);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}

int main() {
    FILE *fp;
    char filename[20];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(0);
    }
    struct resume r;
    read_file(fp, &r);
    print_resume(r);
    fclose(fp);
    return 0;
}