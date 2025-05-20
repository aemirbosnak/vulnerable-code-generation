//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

struct suspect{
    char name[20];
    int age;
    char occupation[20];
    char weapon[20];
};

void searchForSuspect(struct suspect* arr, int length, char* target){
    for(int i=0; i<length; i++){
        if(strcmp(arr[i].name, target) == 0){
            printf("Name: %s\n", arr[i].name);
            printf("Age: %d\n", arr[i].age);
            printf("Occupation: %s\n", arr[i].occupation);
            printf("Weapon: %s\n", arr[i].weapon);
            return;
        }
    }
    printf("Suspect not found.\n");
}

int main(){
    //Create a list of suspects
    struct suspect suspects[5] = {
        {"John Doe", 35, "Engineer", "Knife"},
        {"Jane Smith", 28, "Doctor", "Pistol"},
        {"David Brown", 44, "Lawyer", "Rope"},
        {"Emily Watson", 32, "Journalist", "Poison"},
        {"Mark Davis", 40, "Businessman", "Bat"}
    };
    
    printf("Welcome, detective! We need your help to solve a murder case.\n\n");
    printf("A wealthy businessman was found dead in his office last night. We have reason to believe that the suspect is one of the people who interacted with him in the past 24 hours.\n\n");
    
    printf("Here is a list of people who had access to the victim's office:\n");
    for(int i=0; i<5; i++){
        printf("%s\n", suspects[i].name);
    }
    
    printf("\nWe need you to tell us which person is the most likely suspect based on the evidence we have found.\n\n");
    printf("The evidence suggests that the murder weapon was a blunt object - either a bat or a hammer. We have ruled out the possibility of a knife or a pistol being used.\n\n");
    
    printf("We have also collected some other information about the suspects:\n");
    printf("- John Doe works as an engineer and was seen leaving the victim's office around 9pm last night.\n");
    printf("- Jane Smith is a doctor and had a meeting with the victim yesterday afternoon.\n");
    printf("- David Brown is a lawyer and was seen arguing with the victim in his office yesterday morning.\n");
    printf("- Emily Watson is a journalist who had an interview with the victim yesterday.\n");
    printf("- Mark Davis is a businessman who had a meeting with the victim yesterday afternoon.\n\n");
    
    printf("What is the name of the suspect you would like to investigate?\n");
    char target[20];
    scanf("%s", target);
    
    printf("\nSearching for suspect...\n\n");
    searchForSuspect(suspects, 5, target);
    
    printf("\nThank you for your help, detective. We will continue the investigation based on the information you have provided.\n");
    
    return 0;
}