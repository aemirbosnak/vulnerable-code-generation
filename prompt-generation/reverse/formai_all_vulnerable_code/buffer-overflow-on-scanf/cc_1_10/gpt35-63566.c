//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fortune_teller(){
    int r = rand() % 10;
    if(r == 0){
        printf("Your future is looking bright!\n");
    }
    else if(r == 1){
        printf("You will soon find love in unexpected places.\n");
    }
    else if(r == 2){
        printf("Your hard work will soon pay off.\n");
    }
    else if(r == 3){
        printf("Your career is on the rise!\n");
    }
    else if(r == 4){
        printf("Take that chance, it could change your life.\n");
    }
    else if(r == 5){
        printf("You will have a life-changing experience soon.\n");
    }
    else if(r == 6){
        printf("You are capable of achieving great things.\n");
    }
    else if(r == 7){
        printf("Your friends and family will always have your back.\n");
    }
    else if(r == 8){
        printf("You will be a fortunate person in the near future.\n");
    }
    else if(r == 9){
        printf("Success is just around the corner, keep pushing.\n");
    }
}

int main(){
    srand(time(NULL));
    printf("----------------------------\n");
    printf("|  Welcome to the           |\n");
    printf("|  Automated Fortune Teller |\n");
    printf("----------------------------\n");

    printf("What is your name?\n");
    char name[20];
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("Ask me a question about your future.\n");

    char question[100];
    fgets(question, sizeof(question), stdin);

    printf("\nYour answer is...\n");

    fortune_teller();

    return 0;
}