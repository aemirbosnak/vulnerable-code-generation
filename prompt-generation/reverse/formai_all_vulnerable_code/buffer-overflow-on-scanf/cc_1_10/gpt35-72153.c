//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

int main(){
	float celsius,fahrenheit,inch,centimeter,pound,kilogram;
	int option;

	printf("Welcome to Unit Converter\n");

	while(1){
		printf("\nSelect an option:\n");
		printf("1. Celsius to Fahrenheit\n");
		printf("2. Fahrenheit to Celsius\n");
		printf("3. Inch to Centimeter\n");
		printf("4. Centimeter to Inch\n");
		printf("5. Pound to Kilogram\n");
		printf("6. Kilogram to Pound\n");
		printf("7. Exit\n");
		printf("Enter option number: ");
		scanf("%d",&option);

		switch(option){

			case 1:	{
						printf("\nEnter temperature in Celsius: ");
						scanf("%f",&celsius);
						fahrenheit = (celsius*9/5) + 32;
						printf("%.2f Celsius is equal to %.2f Fahrenheit\n",celsius,fahrenheit);
						break;
					}

			case 2:	{
						printf("\nEnter temperature in Fahrenheit: ");
						scanf("%f",&fahrenheit);
						celsius = (fahrenheit - 32)*5/9;
						printf("%.2f Fahrenheit is equal to %.2f Celsius\n",fahrenheit,celsius);
						break;
					}

			case 3: {
						printf("\nEnter length in inches: ");
						scanf("%f",&inch);
						centimeter = inch * 2.54;
						printf("%.2f inches is equal to %.2f centimeters\n",inch,centimeter);
						break;
					}

			case 4: {
						printf("\nEnter length in centimeters: ");
						scanf("%f",&centimeter);
						inch = centimeter/2.54;
						printf("%.2f centimeters is equal to %.2f inches\n",centimeter,inch);
						break;
					}

			case 5: {
						printf("\nEnter weight in pounds: ");
						scanf("%f",&pound);
						kilogram = pound/2.20462;
						printf("%.2f pounds is equal to %.2f kilograms\n",pound,kilogram);
						break;
					}

			case 6: {
						printf("\nEnter weight in kilograms: ");
						scanf("%f",&kilogram);
						pound = kilogram*2.20462;
						printf("%.2f kilograms is equal to %.2f pounds\n",kilogram,pound);
						break;
					}

			case 7: {
						printf("\nThank you for using Unit Converter\n");
						exit(0);
					}

			default:{
						printf("\nInvalid option, please select a valid option\n");
						break;
					}
		}
	}
	return 0;
}