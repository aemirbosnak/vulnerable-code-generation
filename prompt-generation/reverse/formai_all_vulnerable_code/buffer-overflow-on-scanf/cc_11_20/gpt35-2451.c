//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
#include<stdio.h>

/*Defining the Constants used in the program */

#define MAX_GATES 200 //Maximum number of gates
#define MAX_LEADS 50 //Maximum number of leads

/*Defining the Data Types used in the program*/

/*Gate*/
struct gate_t {
    char *type; //Gate type
    int inp_leads[2]; //Inputs leads
    int out_lead; //Output lead
};

/*Lead*/
struct lead_t {
    char *name; //Lead Name 
    int val; // Lead value
};

/*Prototype Functions used in the program*/

int eval_gate(struct gate_t *gates, struct lead_t *leads, int gate_num); //Evaluate the output of the gate

/*Defining the Global Variables used in the Program*/

int num_gates = 0; //Number of gates
struct gate_t gates[MAX_GATES]; 
int num_leads = 0; //Number of leads
struct lead_t leads[MAX_LEADS]; 

/* Main Function */

int main() {

    char type[10]; //Gate Type

    printf("Enter the Gate Type (AND, OR, NOT) ('q' - to quit):");
    scanf("%s",type);

    while(type[0] != 'q' && num_gates < MAX_GATES){
        gates[num_gates].type = type;

        printf("Enter the two Input Leads:");
        scanf("%d %d", &gates[num_gates].inp_leads[0], &gates[num_gates].inp_leads[1]);

        printf("Enter the Output Lead:");
        scanf("%d", &gates[num_gates].out_lead);

        num_gates++;
        printf("\nEnter the Gate Type (AND, OR, NOT) ('q' - to quit):");
        scanf("%s", type);
    }

    /* Initializing the Lead Values */
    for(int i=0; i<num_leads; i++){
        leads[i].val = -1; //Unidentified State
    }

    /* Evaluating the Leads */
    for(int i=0; i<num_leads; i++){
        if(leads[i].val == -1)
            eval_lead(gates, leads, i);
    }
    return 0; 
}

/* Function to Evaluate the Leads */
int eval_lead(struct gate_t *gates, struct lead_t *leads, int lead_num) {
    int out = -1; //Lead output
    int i;

    /* Evaluating the Gates */
    for(i=0; i<num_gates; i++){
        if(gates[i].out_lead == lead_num){
            switch(*gates[i].type){
                case 'A': //AND Gate
                    if(leads[gates[i].inp_leads[0]].val == 0 || leads[gates[i].inp_leads[1]].val == 0){
                        out = 0;
                    }
                    if(leads[gates[i].inp_leads[0]].val == 1 && leads[gates[i].inp_leads[1]].val == 1){
                        out = 1;
                    }
                    break;
                case 'O': //OR Gate
                    if(leads[gates[i].inp_leads[0]].val == 1 || leads[gates[i].inp_leads[1]].val == 1){
                        out = 1;
                    }
                    if(leads[gates[i].inp_leads[0]].val == 0 && leads[gates[i].inp_leads[1]].val == 0){
                        out = 0;
                    }
                    break;
                case 'N': //NOT Gate
                    if(leads[gates[i].inp_leads[0]].val == 0){
                        out = 1;
                    }
                    else if(leads[gates[i].inp_leads[0]].val == 1){
                        out = 0;
                    }
                    break;
            }
            eval_lead(gates,leads,gates[i].inp_leads[0]);
            eval_lead(gates,leads,gates[i].inp_leads[1]);
        }
    }
    leads[lead_num].val = out;
    return out;
}