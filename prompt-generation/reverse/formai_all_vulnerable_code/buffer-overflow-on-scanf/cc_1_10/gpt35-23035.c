//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){

//Initializing the values
float r1,r2,r3,r4,c1,c2;
float time_step=0.1;
float time_duration=10.0;
float voltage_in=5.0;
float voltage_out=0.0;
float current_in=0.0;
float current_out=0.0;
float charge_c1=0.0;

//Asking the user for input
printf("Enter the value of resistor R1:");
scanf("%f",&r1);

printf("Enter the value of resistor R2:");
scanf("%f",&r2);

printf("Enter the value of resistor R3:");
scanf("%f",&r3);

printf("Enter the value of resistor R4:");
scanf("%f",&r4);

printf("Enter the value of capacitor C1:");
scanf("%f",&c1);

printf("Enter the value of capacitor C2:");
scanf("%f",&c2);

//Calculating the time constant
float tau1=(r1*r2*c1)+(r1*r3*c1)+(r1*r4*c1)+(r2*r4*c1);
float tau2=(r4*c2);
float time_constant=tau1+tau2;

//Calculating the number of time steps
int num_steps=(int)ceil(time_duration/time_step);

//Initializing the arrays to store values
float voltage_out_array[num_steps];
float current_in_array[num_steps];
float current_out_array[num_steps];
float charge_c1_array[num_steps];

//Simulating the circuit
for(int i=0;i<num_steps;i++){

    //Calculating the current flowing into the circuit
    current_in=(voltage_in-voltage_out)/r1;

    //Calculating the charge on the capacitor C1
    charge_c1=charge_c1+(time_step*(current_in-(charge_c1/(r2*c1))));

    //Calculating the voltage across the capacitor C2
    voltage_out=voltage_out+(time_step*(((charge_c1/r2)-(voltage_out/r3))/c1));

    //Calculating the current flowing out of the circuit
    current_out=(voltage_out/r4);

    //Storing the values in the arrays
    voltage_out_array[i]=voltage_out;
    current_in_array[i]=current_in;
    current_out_array[i]=current_out;
    charge_c1_array[i]=charge_c1;

}

//Printing the results
printf("\nVoltage across capacitor C2\n");
for(int i=0;i<num_steps;i++){
    printf("%f ",voltage_out_array[i]);
}

printf("\n\nCurrent flowing into the circuit\n");
for(int i=0;i<num_steps;i++){
    printf("%f ",current_in_array[i]);
}

printf("\n\nCurrent flowing out of the circuit\n");
for(int i=0;i<num_steps;i++){
    printf("%f ",current_out_array[i]);
}

printf("\n\nCharge on capacitor C1\n");
for(int i=0;i<num_steps;i++){
    printf("%f ",charge_c1_array[i]);
}

return 0;
}