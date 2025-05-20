//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the types of data we'll be mining
typedef struct {
    char *name;
    int age;
    char *occupation;
} person;

typedef struct {
    char *name;
    int year;
    char *job;
} job;

// Define the data mining functions
void find_oldest_person(person *people, int num_people);
void find_most_common_job(job *jobs, int num_jobs);

// Main function
int main() {
    // Create a random array of people
    person people[] = {
        { "Alice", 25, "Software Engineer" },
        { "Bob", 30, "Doctor" },
        { "Charlie", 22, "Student" },
        { "Dave", 28, "Lawyer" },
        { "Eve", 26, "Teacher" },
    };

    // Create a random array of jobs
    job jobs[] = {
        { "Software Engineer", 2020, "Alice" },
        { "Doctor", 2015, "Bob" },
        { "Student", 2018, "Charlie" },
        { "Lawyer", 2019, "Dave" },
        { "Teacher", 2017, "Eve" },
    };

    // Find the oldest person
    find_oldest_person(people, 5);

    // Find the most common job
    find_most_common_job(jobs, 5);

    return 0;
}

// Find the oldest person in an array of people
void find_oldest_person(person *people, int num_people) {
    // Initialize the oldest person to the first person in the array
    person oldest_person = people[0];

    // Iterate over the remaining people in the array
    for (int i = 1; i < num_people; i++) {
        // If the current person is older than the oldest person, update the oldest person
        if (people[i].age > oldest_person.age) {
            oldest_person = people[i];
        }
    }

    // Print the name and age of the oldest person
    printf("The oldest person is %s, who is %d years old.\n", oldest_person.name, oldest_person.age);
}

// Find the most common job in an array of jobs
void find_most_common_job(job *jobs, int num_jobs) {
    // Create a hash table to store the number of times each job appears
    int job_counts[100];
    for (int i = 0; i < 100; i++) {
        job_counts[i] = 0;
    }

    // Iterate over the jobs and increment the count for each job
    for (int i = 0; i < num_jobs; i++) {
        job_counts[jobs[i].year]++;
    }

    // Find the job with the highest count
    int max_count = 0;
    job most_common_job;
    for (int i = 0; i < 100; i++) {
        if (job_counts[i] > max_count) {
            max_count = job_counts[i];
            most_common_job = jobs[i];
        }
    }

    // Print the name and year of the most common job
    printf("The most common job is %s, which was held by %d people in %d.\n", most_common_job.name, max_count, most_common_job.year);
}