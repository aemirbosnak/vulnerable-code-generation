//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Calculate Alien Invasion Probability (AIP)
    int AIP = calculate_AIP();

    // Display AIP
    printf("The Alien Invasion Probability (AIP) is: %d%%", AIP);

    return 0;
}

int calculate_AIP()
{
    // Gather data
    int num_saucers = get_num_saucers();
    int num_spacecraft = get_num_spacecraft();
    int num_alien_warriors = get_num_alien_warriors();

    // Calculate AIP
    int AIP = (num_saucers * 20) + (num_spacecraft * 15) + (num_alien_warriors * 10);

    return AIP;
}

int get_num_saucers()
{
    // Prompt user for number of saucers
    int num_saucers = 0;
    printf("Enter the number of saucers: ");
    scanf("%d", &num_saucers);

    return num_saucers;
}

int get_num_spacecraft()
{
    // Prompt user for number of spacecraft
    int num_spacecraft = 0;
    printf("Enter the number of spacecraft: ");
    scanf("%d", &num_spacecraft);

    return num_spacecraft;
}

int get_num_alien_warriors()
{
    // Prompt user for number of alien warriors
    int num_alien_warriors = 0;
    printf("Enter the number of alien warriors: ");
    scanf("%d", &num_alien_warriors);

    return num_alien_warriors;
}