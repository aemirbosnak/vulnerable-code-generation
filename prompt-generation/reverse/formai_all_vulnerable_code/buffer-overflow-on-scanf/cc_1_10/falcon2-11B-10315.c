//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Initialization
    char *candidate_names[] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"};
    int candidate_count = sizeof(candidate_names) / sizeof(candidate_names[0]);

    // Validation
    int input_index;
    printf("Enter the candidate index: ");
    scanf("%d", &input_index);
    if (input_index < 0 || input_index >= candidate_count)
    {
        printf("Invalid input index!\n");
        return 1;
    }

    // Voting process
    printf("Voting for %s...\n", candidate_names[input_index]);
    sleep(2);
    printf("Voting complete!\n");

    // Verification
    if (strcmp(candidate_names[input_index], "Candidate A") == 0)
    {
        printf("Voted for Candidate A!\n");
    }
    else if (strcmp(candidate_names[input_index], "Candidate B") == 0)
    {
        printf("Voted for Candidate B!\n");
    }
    else if (strcmp(candidate_names[input_index], "Candidate C") == 0)
    {
        printf("Voted for Candidate C!\n");
    }
    else if (strcmp(candidate_names[input_index], "Candidate D") == 0)
    {
        printf("Voted for Candidate D!\n");
    }
    else
    {
        printf("Voting error!\n");
        return 1;
    }

    return 0;
}