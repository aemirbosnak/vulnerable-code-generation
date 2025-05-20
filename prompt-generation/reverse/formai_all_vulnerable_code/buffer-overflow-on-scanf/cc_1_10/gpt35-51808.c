//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int life = 100;
int ammo = 50;
int zombies_killed = 0;

int calculate_damage(int accuracy, int power) {
    srand(time(0));
    int hit_chance = rand() % 100 + 1;
    if (hit_chance <= accuracy) {
        int damage = power * (rand() % 3 + 1);
        return damage;
    }
    return 0;
}

void shoot_zombie(int accuracy, int power) {
    int damage = calculate_damage(accuracy, power);
    if (damage == 0) {
        printf("You missed!\n");
    } else {
        printf("You hit the zombie for %d damage!\n", damage);
        zombies_killed++;
    }
    ammo--;
}

void run_math_game() {
    printf("Welcome to the post-apocalyptic math game!\n");
    printf("The world has ended and it's up to you to survive and reclaim what's left.\n");
    printf("You start with %d life points and %d ammo.\n", life, ammo);
    printf("Each question answered correctly will give you more ammo, but each incorrect answer will cost you life.\n");
    printf("You'll need to conserve your ammo and manage your resources to stay alive.\n");
    
    int num_questions = 10;
    int correct_answers = 0;
    for (int i = 1; i <= num_questions; i++) {
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        char operator = rand() % 3 == 0 ? '+' : rand() % 3 == 1 ? '-' : '*';
        int answer;
        switch (operator) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
        }
        printf("Question %d: What is %d %c %d?\n", i, num1, operator, num2);
        int player_answer;
        scanf("%d", &player_answer);
        if (player_answer == answer) {
            printf("Correct!\n");
            int extra_ammo = rand() % 5 + 1;
            printf("You gained %d extra ammo!\n", extra_ammo);
            ammo += extra_ammo;
            correct_answers++;
        } else {
            printf("Incorrect!\n");
            life -= 10;
        }
        printf("Current life: %d, current ammo: %d\n", life, ammo);
        if (life <= 0) {
            printf("GAME OVER! You died.\n");
            return;
        }
        if (i == num_questions) {
            printf("You've completed all the math questions! Now it's time to test your survival skills.\n");
        } else {
            printf("Press enter to continue to the next question.\n");
            getchar();
        }
    }
    
    printf("You are now surrounded by a horde of zombies!\n");
    printf("You have to fight them off with your weapon. Each shot will require one ammo.\n");
    printf("You have to kill as many zombies as possible before you run out of ammo or life points.\n");
    printf("You get a hit if a random number between 1 and 100 is less than your accuracy.\n");
    printf("Each hit will deal between 1 and 3 times of your weapon power.\n");
    
    int accuracy, power;
    printf("What is your accuracy level (between 1 and 100)?\n");
    scanf("%d", &accuracy);
    printf("What is your weapon power?\n");
    scanf("%d", &power);
    
    while (ammo > 0 && life > 0) {
        printf("Press enter to shoot.\n");
        getchar();
        shoot_zombie(accuracy, power);
        printf("Zombies killed: %d, current ammo: %d, current life: %d\n", zombies_killed, ammo, life);
    }
    
    if (ammo <= 0) {
        printf("GAME OVER! You ran out of ammo and were overwhelmed by the zombies.\n");
    } else {
        printf("CONGRATULATIONS! You killed %d zombies before you were overrun.\n", zombies_killed);
    }
}

int main() {
    run_math_game();
    return 0;
}