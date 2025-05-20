//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    srand(time(NULL)); //seeding random number generator
    char name[30];
    int age, planet_size, weapon_avail, government_type;
    float invasion_prob = 0.0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please answer the following questions to find out the likelihood of your planet being invaded.\n");

    printf("What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);
    
    if (age <= 18)
    {
        printf("Sorry, you must be at least 18 years old to use the Alien Invasion Probability Calculator.\n");
        return 0;
    }

    printf("What is the size of your planet in square kilometers?\n");
    scanf("%d", &planet_size);

    printf("How many weapons does your planet have for self-defense? Enter 1 for none, 2 for few, 3 for moderate, or 4 for many.\n");
    scanf("%d", &weapon_avail);

    printf("What type of government do you have? Enter 1 for democratic, 2 for communist, 3 for dictatorship, or 4 for monarchy.\n");
    scanf("%d", &government_type);

    int rand_num = rand()%101; //generating a random number between 0 and 100
    
    if(government_type == 3) //if dictatorship, increase invasion probability by 10%
    {
        invasion_prob += 0.1;
    }

    if(weapon_avail == 1) //if no weapons, increase invasion probability by 40%
    {
        invasion_prob += 0.4;
    }
    else if(weapon_avail == 2) //if few weapons, increase invasion probability by 20%
    {
        invasion_prob += 0.2;
    }

    if(planet_size > 1000000000) //if planet is larger than 1 billion km^2, decrease invasion probability by 10%
    {
        invasion_prob -= 0.1;
    }

    //generating a random invasion probability factor based on age
    if(age > 50)
    {
        invasion_prob += ((float) rand_num / 100) * 0.2;
    }
    else if(age > 30)
    {
        invasion_prob += ((float) rand_num / 100) * 0.1;
    }
    else
    {
        invasion_prob += ((float) rand_num / 100) * 0.05;
    }

    if(invasion_prob > 0.75) //if invasion probability is over 75%, chance of invasion is high
    {
        printf("WARNING, %s! The chance of an alien invasion on your planet is very high at %.2f%%.\n", name, invasion_prob*100);
    }
    else if(invasion_prob > 0.50) //if invasion probability is between 50% and 75%, chance of invasion is moderate
    {
        printf("ATTENTION, %s! The chance of an alien invasion on your planet is moderate at %.2f%%.\n", name, invasion_prob*100);
    }
    else //if invasion probability is less than 50%, chance of invasion is low
    {
        printf("GOOD NEWS, %s! The chance of an alien invasion on your planet is low at %.2f%%.\n", name, invasion_prob*100);
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");

    return 0;
}