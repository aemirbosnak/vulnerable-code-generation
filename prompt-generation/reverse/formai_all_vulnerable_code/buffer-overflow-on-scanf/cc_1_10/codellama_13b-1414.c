//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_EMAIL_LEN 64

struct Person {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

void read_data(struct Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Enter name: ");
        scanf("%s", people[i].name);
        printf("Enter email: ");
        scanf("%s", people[i].email);
    }
}

void write_data(struct Person *people, int num_people) {
    FILE *fp = fopen("data.txt", "w");
    for (int i = 0; i < num_people; i++) {
        fprintf(fp, "%s\n%s\n", people[i].name, people[i].email);
    }
    fclose(fp);
}

void recover_data(struct Person *people, int num_people) {
    FILE *fp = fopen("data.txt", "r");
    for (int i = 0; i < num_people; i++) {
        fscanf(fp, "%s %s", people[i].name, people[i].email);
    }
    fclose(fp);
}

int main() {
    int num_people;
    printf("Enter number of people: ");
    scanf("%d", &num_people);

    struct Person *people = malloc(num_people * sizeof(struct Person));
    read_data(people, num_people);
    write_data(people, num_people);
    recover_data(people, num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\nEmail: %s\n", people[i].name, people[i].email);
    }

    free(people);
    return 0;
}