//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100
#define MAX_SKILL_LEN 30

typedef struct resume {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    char skills[10][MAX_SKILL_LEN];
    int num_skills;
    struct resume *next;
} resume;

void print_menu();
void parse_resume(FILE *fp, resume **head);

int main(int argc, char *argv[]) {
    resume *head = NULL;
    FILE *fp;

    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    parse_resume(fp, &head);
    fclose(fp);

    print_menu(&head);

    while (getchar() != EOF) {}

    while (head != NULL) {
        resume *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void print_menu(resume **head) {
    int choice;
    resume *curr = *head;

    while (1) {
        printf("\nresume parser menu:\n");
        printf("1. Display next resume\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 && curr != NULL) {
            printf("\nName: %s\n", curr->name);
            printf("Phone: %s\n", curr->phone);
            printf("Email: %s\n", curr->email);
            printf("Skills:\n");
            for (int i = 0; i < curr->num_skills; i++) {
                printf("- %s\n", curr->skills[i]);
            }
            curr = curr->next;
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice, try again.\n");
        }
    }
}

void parse_resume(FILE *fp, resume **head) {
    resume *new_resume;
    char line[100];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if ((new_resume = (resume *)malloc(sizeof(resume))) == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1);
        }

        sscanf(line, "%s %s %s", new_resume->name, new_resume->phone, new_resume->email);

        if (*head == NULL) {
            *head = new_resume;
        } else {
            resume *curr = *head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_resume;
        }

        new_resume->next = NULL;

        int i = 0;
        while (fgets(line, sizeof(line), fp) != NULL && i < 10) {
            sscanf(line, "%s", new_resume->skills[i]);
            i++;
        }
        new_resume->num_skills = i;
    }
}