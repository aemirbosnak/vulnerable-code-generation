//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#define ADMIN_PIN 1234

struct candidate{
    int id;
    char name[30];
    int vote_count;
};

struct voter{
    int id;
    char name[30];
    int has_voted;
};

void print_candidate(struct candidate c){
    printf("%d. %s (%d)\n", c.id, c.name, c.vote_count);
}

void cast_vote(struct voter *v, struct candidate *candidates, int num_candidates){
    int candidate_id;
    printf("List of candidates:\n");
    for(int i=0;i<num_candidates;i++){
        print_candidate(candidates[i]);
    }
    printf("Enter candidate ID to vote: ");
    scanf("%d", &candidate_id);
    
    for(int i=0;i<num_candidates;i++){
        if(candidates[i].id == candidate_id){
            candidates[i].vote_count += 1;
            printf("Vote casted successfully!\n");
            v->has_voted = 1;
            return;
        }
    }
    printf("Invalid candidate ID selected. Please try again.\n");
}

int authenticate_admin(){
    int pin;
    printf("Enter admin PIN: ");
    scanf("%d", &pin);
    if(pin == ADMIN_PIN){
        return 1;
    }
    else{
        return 0;
    }
}

void add_candidate(struct candidate *candidates, int *num_candidates){
    printf("Enter candidate name: ");
    char name[30];
    scanf("%s", name);
    candidates[*num_candidates].id = *num_candidates+1;
    strcpy(candidates[*num_candidates].name, name);
    candidates[*num_candidates].vote_count = 0;
    *num_candidates += 1;
    printf("Candidate added successfully!\n");
}

void print_voter(struct voter v){
    printf("%d. %s (%s)\n", v.id, v.name, v.has_voted==1?"Voted":"Not Voted");
}

void print_election_results(struct candidate *candidates, int num_candidates){
    printf("\nElection Results: \n");
    for(int i=0;i<num_candidates;i++){
        print_candidate(candidates[i]);
    }
}

void print_voter_list(struct voter *voters, int num_voters){
    printf("\nVoter List: \n");
    for(int i=0;i<num_voters;i++){
        print_voter(voters[i]);
    }
}

int main(){
    int num_voters = 3;
    struct voter voters[3] = {
        {1, "John Doe", 0},
        {2, "Jane Doe", 0},
        {3, "Bob Smith", 0}
    };
    
    int num_candidates = 0;
    struct candidate candidates[10];
    
    int is_admin = 0;
    do{
        printf("\nEnter login type:\n");
        printf("1. Voter\n");
        printf("2. Admin\n");
        printf("3. Exit\n");
        int login_type;
        scanf("%d", &login_type);
        switch(login_type){
            case 1:
                printf("\nEnter voter ID: ");
                int voter_id;
                scanf("%d", &voter_id);
                if(voter_id > 0 && voter_id <= num_voters){
                    if(voters[voter_id-1].has_voted == 0){
                        cast_vote(&voters[voter_id-1], candidates, num_candidates);
                    }
                    else{
                        printf("You have already voted!\n");
                    }
                }
                else{
                    printf("Invalid voter ID selected!\n");
                }
                break;
            case 2:
                printf("\n");
                if(is_admin == 0){
                    if(authenticate_admin() == 1){
                        is_admin = 1;
                    }
                    else{
                        printf("Invalid admin PIN entered!\n");
                    }
                }
                if(is_admin == 1){
                    printf("\nEnter admin option:\n");
                    printf("1. Add candidate\n");
                    printf("2. View Results\n");
                    printf("3. View Voter List\n");
                    printf("4. Logout\n");
                    int admin_option;
                    scanf("%d", &admin_option);
                    switch(admin_option){
                        case 1:
                            add_candidate(candidates, &num_candidates);
                            break;
                        case 2:
                            print_election_results(candidates, num_candidates);
                            break;
                        case 3:
                            print_voter_list(voters, num_voters);
                            break;
                        case 4:
                            is_admin = 0;
                            break;
                        default:
                            printf("Invalid option selected.\n");
                            break;
                    }
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }while(1);
    return 0;
}