//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    char name[20];
    int age;

    printf("Greetings, I am a Fortune Teller program. Please enter your name: ");
    scanf("%s", name);
    printf("%s, please enter your age: ", name);
    scanf("%d", &age);

    if(age < 18){
        printf("I'm sorry %s, but I cannot provide fortune telling for those under the age of 18.\n", name);
        exit(0);
    }

    printf("Thank you, %s. Now let me calculate your fortune...\n\n", name);

    srand(time(0));
    int num = rand()%10;

    switch(num){
        case 0:
            printf("%s, you will have a very successful career in the future. Keep working hard!\n", name);
            break;
        case 1:
            printf("%s, you will meet the love of your life in the near future. Be ready!\n", name);
            break;
        case 2:
            printf("%s, you will receive unexpected news that will change your life forever.\n", name);
            break;
        case 3:
            printf("%s, you will travel to a foreign land in the next year and experience new things!\n", name);
            break;
        case 4:
            printf("%s, you will face a difficult decision in the near future. Stay true to yourself!\n", name);
            break;
        case 5:
            printf("%s, it is time for you to take a break and relax. Your body and mind need it.\n", name);
            break;
        case 6:
            printf("%s, you will receive unexpected financial gain in the near future. Use it wisely!\n", name);
            break;
        case 7:
            printf("%s, you will meet someone who will change your life forever.\n", name);
            break;
        case 8:
            printf("%s, you will face a challenge that will require you to be brave and strong. You can do it!\n", name);
            break;
        case 9:
            printf("%s, you will receive unexpected help from someone you least expect. Be grateful!\n", name);
            break;
    }

    return 0;
}