//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

  // Defining the variables
  int passengerID, bags, weight, destination;
  int num_of_passengers = 0, total_bags = 0, total_weight = 0;
  float avg_bags_per_passenger, avg_weight_per_bag;
  char choice;

  // Introduction
  printf("Welcome to the Airport Baggage Handling Simulation Program!\n\n");

  // Loop for entering passenger details
  do{
    printf("Enter Passenger ID: ");
    scanf("%d", &passengerID);
    printf("Enter Number of Bags: ");
    scanf("%d", &bags);
    printf("Enter Total Weight of Bags (in KGs): ");
    scanf("%d", &weight);
    printf("Enter Destination Code: ");
    scanf("%d", &destination);
    printf("\n");

    // Updating the variables
    num_of_passengers++;
    total_bags += bags;
    total_weight += weight;

    // Prompting the user for more passengers
    printf("Do you want to enter details for another passenger? (Y/N): ");
    scanf(" %c", &choice);
  } while(choice == 'Y' || choice == 'y');

  // Calculating the averages
  avg_bags_per_passenger = (float)total_bags / num_of_passengers;
  avg_weight_per_bag = (float)total_weight / total_bags;

  // Displaying the results
  printf("\nTotal Number of Passengers: %d\n", num_of_passengers);
  printf("Total Number of Bags: %d\n", total_bags);
  printf("Total Weight of Bags: %d KGs\n", total_weight);
  printf("Average Number of Bags per Passenger: %.2f\n", avg_bags_per_passenger);
  printf("Average Weight per Bag: %.2f KGs\n", avg_weight_per_bag);

  return 0;
}