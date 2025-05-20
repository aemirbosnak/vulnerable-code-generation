//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

char cell[9] = {'1','2','3','4','5','6','7','8','9'}; 
char player = 'X'; 
int moves = 0; 

void print_board(){
	printf(" %c | %c | %c\n", cell[0], cell[1], cell[2]);
	printf("___|___|___\n");
	printf(" %c | %c | %c\n", cell[3], cell[4], cell[5]);
	printf("___|___|___\n");
	printf(" %c | %c | %c\n", cell[6], cell[7], cell[8]);
	printf("   |   |   \n");
}

void player_turn(){
	int choice;
	printf("Player %c, enter the cell number: ",player);
	scanf("%d",&choice);
	if(choice>=1 && choice<=9 && cell[choice-1] != 'X' && cell[choice-1] != 'O'){
		cell[choice-1] = player;
		moves++;
	}
	else{
		printf("Invalid Choice!\n");
		player_turn();
	}
}

int check_win(){
	if(cell[0] == cell[1] && cell[1] == cell[2])
		return 1;
	else if(cell[3] == cell[4] && cell[4] == cell[5])
		return 1;
	else if(cell[6] == cell[7] && cell[7] == cell[8])
		return 1;
		
	else if(cell[0] == cell[3] && cell[3] == cell[6])
		return 1;
	else if(cell[1] == cell[4] && cell[4] == cell[7])
		return 1;
	else if(cell[2] == cell[5] && cell[5] == cell[8])
		return 1;
		
	else if(cell[0] == cell[4] && cell[4] == cell[8])
		return 1;
	else if(cell[2] == cell[4] && cell[4] == cell[6])
		return 1;
		
	else if(moves == 9)
		return 0;
		
	else
		return -1;
}

void computer_turn(){
    printf("Computer's Turn: ");
    for(int i=1;i<=9;i++){
        if(cell[i-1]!='X' && cell[i-1]!='O'){
            cell[i-1] = 'O'; // Computer Input
            moves++;
            printf("Cell %d Selected!\n", i);
            break;
        }
    }
}

void get_player(){
	if(player == 'X')
		player = 'O';
	else
		player = 'X';
}

int main(){
	printf("-------------------------\n");
	printf("      TIC-TAC-TOE\n");
	printf("-------------------------\n\n");
	print_board();
	while(1){
		get_player();
		if(player == 'X'){
			player_turn();
			print_board();
			if(check_win() == 1){
				printf("Player X Wins!\n");
				break;
			}
			else if(check_win() == 0){
				printf("It's a Draw!\n");
				break;
			}
		}	
		else{
			computer_turn();
			print_board();
			if(check_win() == 1){
				printf("Player O Wins!\n");
				break;
			}
			else if(check_win() == 0){
				printf("It's a Draw!\n");
				break;
			}
		}
	}
	return 0;
}