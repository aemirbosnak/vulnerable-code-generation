//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

char choice[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void print_board() {          // Function to print the board
    printf("\n\n\t%c | %c | %c\n", choice[0], choice[1], choice[2]);
    printf("\t--|---|--\n");
    printf("\t%c | %c | %c\n", choice[3], choice[4], choice[5]);
    printf("\t--|---|--\n");
    printf("\t%c | %c | %c\n\n", choice[6], choice[7], choice[8]);
}

int check_win() {           // Function to check for winner
    if(choice[0] == choice[1] && choice[1] == choice[2])
        return 1;
    else if(choice[3] == choice[4] && choice[4] == choice[5])
        return 1;
    else if(choice[6] == choice[7] && choice[7] == choice[8])
        return 1;
    else if(choice[0] == choice[3] && choice[3] == choice[6])
        return 1;
    else if(choice[1] == choice[4] && choice[4] == choice[7])
        return 1;
    else if(choice[2] == choice[5] && choice[5] == choice[8])
        return 1;
    else if(choice[0] == choice[4] && choice[4] == choice[8])
        return 1;
    else if(choice[2] == choice[4] && choice[4] == choice[6])
        return 1;
    else if(choice[0]!='1' && choice[1]!='2' && choice[2]!='3' && choice[3]!='4' 
    && choice[4]!='5' && choice[5]!='6' && choice[6]!='7' && choice[7]!='8' && choice[8]!='9')
        return 0;
    else
        return -1;
}

int check_choice(int ch) {         // Function to check if entered position is valid
    if(choice[ch-1] == 'X' || choice[ch-1] == 'O') {
        return -1;
    }
    else {
        return 1;
    }
}

int computer_input() {            // Function for computer's move
    int i, p=0, score, max_score=-9999;
    char best_move;
    int flag = 0;
    
    for(i=0;i<9;i++) {
        if(choice[i] != 'X' && choice[i] != 'O') {
            flag = 1;
            choice[i] = 'O';
            score = mini_max_algorithm(1);
            choice[i] = (i+1)+'0';
            if(score > max_score) {
                max_score = score;
                best_move = (i+1)+'0';
            }
        }
    }
    
    if(flag == 0) {
        return -1;
    }
    else {
        choice[best_move-'1'] = 'O';
        printf("Computer placed an 'O' in position %c\n", best_move);
        print_board();
        return 1;
    }
}

int mini_max_algorithm(int depth) {            // Function for minimax algorithm
    int i, p=0, score, max_score=-9999, min_score=9999;
    int result;
    
    result = check_win();
    
    if(result != -1) {
        if(result == 1) {
            return -10 + depth;
        }
        else {
            return 0;
        }
    }
    
    for(i=0;i<9;i++) {
        if(choice[i] != 'X' && choice[i] != 'O') {
            choice[i] = 'X';
            score = mini_max_algorithm(depth+1);
            if(score > max_score) {
                max_score = score;
            }
            choice[i] = (i+1)+'0';
            if(score < min_score) {
                min_score = score;
            }
        }
    }
    
    if(max_score > -min_score) {
        return max_score;
    }
    else {
        return min_score;
    }
}

int main() {            // Main function
    int player_1_choice, player_2_choice, player_2_input, result;
    printf("\n\n\tTic Tac Toe\n");
    printf("\nPlayer 1: X \nPlayer 2: O\n\n");
    print_board();
    
    while(1) {
        printf("\nPlayer 1 enter move : ");
        scanf("%d", &player_1_choice);
        if(check_choice(player_1_choice) == -1) {
            printf("\nInvalid move! Please try again.\n");
            continue;
        }
        else {
            choice[player_1_choice-1] = 'X';
            print_board();
            result = check_win();
            if(result == 1) {
                printf("\nPlayer 1 wins!\n");
                break;
            }
            else if(result == 0) {
                printf("\nGame Drawn!\n");
                break;
            }
        }
        
        player_2_input = computer_input();
        if(player_2_input == -1) {
            printf("\nGame Drawn!\n");
            break;
        }
        
        result = check_win();
        if(result == 1) {
            printf("\nComputer wins!\n");
            break;
        }
        else if(result == 0) {
            printf("\nGame Drawn!\n");
            break;
        }
    }
    return 0;
}