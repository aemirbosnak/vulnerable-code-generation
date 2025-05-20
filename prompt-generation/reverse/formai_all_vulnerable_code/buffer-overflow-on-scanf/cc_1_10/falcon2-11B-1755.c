//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char gender[5];
    int roll_no;
} Student;

typedef struct {
    int choice;
    Student data;
} ElectionData;

int main() {
    int choice, i, num_votes;
    ElectionData votes[50];
    char name[50];
    int age, roll_no;
    char gender[5];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name: ");
    fgets(name, 50, stdin);
    fgets(name, 50, stdin);

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your gender: ");
    fgets(gender, 5, stdin);

    printf("Please enter your roll number: ");
    scanf("%d", &roll_no);

    for (i = 0; i < 50; i++) {
        votes[i].choice = 0;
        votes[i].data.name[0] = '\0';
        votes[i].data.age = 0;
        votes[i].data.gender[0] = '\0';
        votes[i].data.roll_no = 0;
    }

    printf("Please enter your choice (0 to 49): ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= 50) {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    printf("Please enter the name of the candidate: ");
    fgets(votes[choice].data.name, 50, stdin);
    fgets(votes[choice].data.name, 50, stdin);

    printf("Please enter the age of the candidate: ");
    scanf("%d", &votes[choice].data.age);

    printf("Please enter the gender of the candidate: ");
    fgets(votes[choice].data.gender, 5, stdin);

    printf("Please enter the roll number of the candidate: ");
    scanf("%d", &votes[choice].data.roll_no);

    num_votes = 0;

    printf("Votes Cast: ");
    for (i = 0; i < 50; i++) {
        if (votes[i].choice == 1) {
            num_votes++;
        }
    }

    printf("%d votes have been cast.\n", num_votes);

    return 0;
}