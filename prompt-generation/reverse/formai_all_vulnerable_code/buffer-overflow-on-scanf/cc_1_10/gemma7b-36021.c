//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    system("rm -rf ./*");
    system("mkdir -p .");
    system("touch voter_list.txt");

    FILE *fp = fopen("voter_list.txt", "a");

    char name[20], vote[20], ip[20];
    int i, r, v, n = 0;

    time_t t = time(NULL);

    while (1) {
        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter your IP address: ");
        scanf("%s", ip);

        r = validate_voter(name, ip);

        if (r == 0) {
            printf("You are not eligible to vote.\n");
            continue;
        }

        printf("Enter your vote: ");
        scanf("%s", vote);

        v = store_vote(name, vote);

        if (v == 0) {
            printf("Your vote has not been stored.\n");
            continue;
        }

        n++;

        printf("Thank you for voting. Your vote has been recorded.\n");

        if (n == 10) {
            fclose(fp);
            system("rm -rf ./*");
            printf("Voting complete. Results will be displayed later.\n");
            break;
        }
    }

    return 0;
}

int validate_voter(char *name, char *ip) {
    FILE *fp = fopen("voter_list.txt", "r");

    char voter_name[20], voter_ip[20];

    while (fscanf(fp, "%s %s", voter_name, voter_ip) != EOF) {
        if (strcmp(name, voter_name) == 0 && strcmp(ip, voter_ip) == 0) {
            return 0;
        }
    }

    fclose(fp);

    return 1;
}

int store_vote(char *name, char *vote) {
    FILE *fp = fopen("voter_list.txt", "a");

    fprintf(fp, "%s, %s\n", name, vote);

    fclose(fp);

    return 1;
}