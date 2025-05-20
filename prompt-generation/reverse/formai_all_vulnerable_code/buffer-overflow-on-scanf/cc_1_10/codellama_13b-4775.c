//Code Llama-13B DATASET v1.0 Category: Greedy Algorithms ; Style: genius
/*
 * A genius-style C Greedy Algorithms example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 256
#define MAX_JOBS 100

typedef struct {
    char name[MAX_NAME_LEN];
    int job_id;
    int score;
} Person;

int cmp_score(const void *a, const void *b) {
    return ((Person *)b)->score - ((Person *)a)->score;
}

int main() {
    Person people[MAX_JOBS];
    int n_people = 0;
    int n_jobs = 0;
    int n_allocated = 0;
    int n_completed = 0;

    // Read the number of people and jobs from the user
    printf("Enter the number of people: ");
    scanf("%d", &n_people);
    printf("Enter the number of jobs: ");
    scanf("%d", &n_jobs);

    // Read the names and scores of the people from the user
    for (int i = 0; i < n_people; i++) {
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter the score of person %s: ", people[i].name);
        scanf("%d", &people[i].score);
    }

    // Sort the people by score in descending order
    qsort(people, n_people, sizeof(Person), cmp_score);

    // Allocate jobs to people
    for (int i = 0; i < n_jobs; i++) {
        // Find the person with the highest score
        Person *best_person = &people[0];

        // Find the person with the highest score that has not been allocated a job
        for (int j = 1; j < n_people; j++) {
            if (people[j].score > best_person->score && people[j].job_id == 0) {
                best_person = &people[j];
            }
        }

        // Allocate the job to the person with the highest score
        best_person->job_id = i + 1;
        n_allocated++;
    }

    // Print the number of jobs allocated and completed
    printf("Number of jobs allocated: %d\n", n_allocated);
    printf("Number of jobs completed: %d\n", n_completed);

    return 0;
}