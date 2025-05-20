#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char candidate_name[100];
    int voter_id;

    printf("Enter candidate name: ");
    scanf("%s", candidate_name);

    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    printf("Candidate name: %s\n", candidate_name);
    printf("Voter ID: %d\n", voter_id);

    return 0;
}
