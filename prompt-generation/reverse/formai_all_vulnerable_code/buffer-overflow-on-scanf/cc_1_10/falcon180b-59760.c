//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_OF_FORTUNE_TELLERS 10
#define MAX_NUM_OF_USERS 100
#define MAX_NUM_OF_FORTUNE_TELLER_RESPONSES 100

typedef struct {
    char name[20];
    int num_of_responses;
    char *responses[MAX_NUM_OF_FORTUNE_TELLER_RESPONSES];
} FortuneTeller;

int main() {
    int num_of_users, num_of_fortune_tellers;
    FortuneTeller fortune_tellers[MAX_NUM_OF_FORTUNE_TELLERS];
    char input[100];
    int i, j, k;
    int fortune_teller_index;
    time_t seed;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("How many users will be using the fortune teller? ");
    scanf("%d", &num_of_users);

    printf("How many fortune tellers do you want to use? ");
    scanf("%d", &num_of_fortune_tellers);

    srand(time(&seed));

    for (i = 0; i < num_of_fortune_tellers; i++) {
        fortune_tellers[i].num_of_responses = 0;
    }

    printf("Enter the names of the fortune tellers:\n");
    for (i = 0; i < num_of_fortune_tellers; i++) {
        scanf("%s", fortune_tellers[i].name);
    }

    printf("Enter the responses for each fortune teller:\n");
    for (i = 0; i < num_of_fortune_tellers; i++) {
        for (j = 0; j < MAX_NUM_OF_FORTUNE_TELLER_RESPONSES; j++) {
            scanf("%s", fortune_tellers[i].responses[j]);
        }
    }

    printf("Enter your question:\n");
    scanf("%s", input);

    fortune_teller_index = rand() % num_of_fortune_tellers;

    printf("Fortune Teller: %s\n", fortune_tellers[fortune_teller_index].name);
    printf("Question: %s\n", input);

    for (k = 0; k < fortune_tellers[fortune_teller_index].num_of_responses; k++) {
        printf("Response %d: %s\n", k+1, fortune_tellers[fortune_teller_index].responses[k]);
    }

    return 0;
}