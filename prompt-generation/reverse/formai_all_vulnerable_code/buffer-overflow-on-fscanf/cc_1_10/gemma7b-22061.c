//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char username[20];
    char password[20];
    int vote_choice;
    int candidate_id;
    int total_votes;
    char candidate_name[50];

    // Database Connection
    FILE *fp = fopen("voting_system.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // User Authentication
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Validate User Credentials
    if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0)
    {
        // Admin Panel
        printf("Welcome, Admin!\n");

        // Total Votes
        printf("Total Votes: ");
        fscanf(fp, "%d", &total_votes);
        printf("%d\n", total_votes);

        // Candidate List
        printf("Candidates:\n");
        while (fscanf(fp, "%d %s", &candidate_id, candidate_name) != EOF)
        {
            printf("%d. %s\n", candidate_id, candidate_name);
        }

        // Vote Casting
        printf("Enter candidate ID: ");
        scanf("%d", &candidate_id);

        // Validate Candidate ID
        if (candidate_id < 1 || candidate_id > total_votes)
        {
            printf("Invalid candidate ID.\n");
            return 1;
        }

        // Record Vote
        fprintf(fp, "Vote cast for candidate %d by user %s\n", candidate_id, username);

        // Update Total Votes
        fscanf(fp, "%d", &total_votes);
        total_votes++;
        fprintf(fp, "Total Votes: %d\n", total_votes);

        // Save Changes
        fclose(fp);
        fp = fopen("voting_system.txt", "w");
        fprintf(fp, "Total Votes: %d\n", total_votes);
        fclose(fp);

        // Success Message
        printf("Vote cast successfully!\n");
    }
    else
    {
        // User Panel
        printf("Welcome, User!\n");

        // Candidate List
        printf("Candidates:\n");
        while (fscanf(fp, "%d %s", &candidate_id, candidate_name) != EOF)
        {
            printf("%d. %s\n", candidate_id, candidate_name);
        }

        // Vote Casting
        printf("Enter candidate ID: ");
        scanf("%d", &candidate_id);

        // Validate Candidate ID
        if (candidate_id < 1 || candidate_id > total_votes)
        {
            printf("Invalid candidate ID.\n");
            return 1;
        }

        // Record Vote
        fprintf(fp, "Vote cast for candidate %d by user %s\n", candidate_id, username);

        // Success Message
        printf("Vote cast successfully!\n");
    }

    return 0;
}