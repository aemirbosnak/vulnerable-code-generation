//FormAI DATASET v1.0 Category: Database querying ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    char *name;
    int age;
    int iq;
    char *profession;
} person;

int main(){
    // Initialize random seed
    srand(time(NULL));
    
    // Create database of people
    int num_people = rand() % 10 + 1; // Generate random number of people
    person *people = malloc(num_people * sizeof(person));
    
    // Populate database with surreal data
    for(int i=0; i<num_people; i++){
        // Generate name of person
        char *name = malloc(10 * sizeof(char));
        if(rand() % 2 == 0){
            name = "Bob";
        } else {
            name = "Alice";
        }
        
        // Set age and IQ of person randomly
        int age = rand() % 120 + 1;
        int iq = rand() % 200 + 1;
        
        // Choose profession of person randomly
        char *profession = malloc(20 * sizeof(char));
        switch(rand() % 5 + 1){
            case 1: 
                profession = "Unicorn Wrangler"; 
                break;
            case 2: 
                profession = "Dream Interpreter"; 
                break;
            case 3: 
                profession = "Galactic Traveler"; 
                break;
            case 4: 
                profession = "Tooth Fairy"; 
                break;
            case 5: 
                profession = "Time Traveler"; 
                break;
            default: 
                profession = "Error"; 
                break;
        }
        
        // Add person to database
        people[i].name = name;
        people[i].age = age;
        people[i].iq = iq;
        people[i].profession = profession;
    }
    
    // Query database based on surreal characteristics
    for(int i=0; i<num_people; i++){
        if(people[i].age > 100 && people[i].iq > 150 && people[i].name == "Alice"){
            printf("Congratulations! You have found Alice, the legendary time traveler!\n");
            break;
        } else if(people[i].profession == "Unicorn Wrangler"){
            printf("You have found a rare breed! A real-life Unicorn Wrangler. \n");
        }
    }
    
    // Free memory allocated to people
    for(int i=0; i<num_people; i++){
        free(people[i].name);
        free(people[i].profession);
    }
    free(people);
    
    return 0;
}