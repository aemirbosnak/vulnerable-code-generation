//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Struct to hold information about players
struct player{
    int id;
    char name[50];
    int password_strength;
}players[10];

// Function to check password strength
int check_password_strength(char* password){
    int len = strlen(password);
    int strength = 0;
    int flag_upper = 0, flag_lower = 0, flag_num = 0, flag_special = 0;
    for(int i = 0; i < len; i++){
        if(password[i] >= 'A' && password[i] <= 'Z')
            flag_upper = 1;
        if(password[i] >= 'a' && password[i] <= 'z')
            flag_lower = 1;
        if(password[i] >= '0' && password[i] <= '9')
            flag_num = 1;
        if(password[i] == '@' || password[i] == '#' || password[i] == '$')
            flag_special = 1;
    }
    if(flag_upper == 1 && flag_lower == 1 && flag_num == 1 && flag_special == 1)
        strength = 4;
    else if(flag_upper == 1 && flag_lower == 1 && flag_num == 1)
        strength = 3;
    else if((flag_upper == 1 || flag_lower == 1) && flag_num == 1)
        strength = 2;
    else if((flag_upper == 1 || flag_lower == 1) && len >= 8)
        strength = 1;
    else
        strength = 0;
    return strength;
}

int main(){
    int num_players;
    char password[20];
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    for(int i = 0; i < num_players; i++){
        printf("Enter the name of Player %d: ", i+1);
        scanf("%s", players[i].name);
        printf("Enter the password for Player %d: ", i+1);
        scanf("%s", password);
        players[i].password_strength = check_password_strength(password);
        printf("Password Strength of Player %d: %d\n", i+1, players[i].password_strength);
    }
    return 0;
}