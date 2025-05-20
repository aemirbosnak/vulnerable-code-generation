//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include<stdio.h>

struct Resume {
    char name[20];
    char address[50];
    char phone[15];
    char email[50];
    char skills[100];
} resume;

int main() {
    FILE* fp;
    char c;
    int count = 0, i = 0;

    fp = fopen("resume.txt", "r");

    while((c = fgetc(fp)) != EOF) {
        if(c == ',') {
            count++;
            i = 0;
        } else if(c == '\n') {
            count = 0;
            i = 0;
        } else {
            switch(count) {
                case 0:
                    resume.name[i] = c;
                    break;
                case 1:
                    resume.address[i] = c;
                    break;
                case 2:
                    resume.phone[i] = c;
                    break;
                case 3:
                    resume.email[i] = c;
                    break;
                case 4:
                    resume.skills[i] = c;
                    break;
            }
            i++;
        }
    }

    fclose(fp);

    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);

    return 0;
}