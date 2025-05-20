//FormAI DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
	char choice;
	float red, green, blue;
	int hex[6] = { 0 };
	printf("Welcome to the Color Code Converter!\n");
	
	while (1) {
		printf("\nWhat would you like to do?\n");
		printf("A – Convert RGB value to HEX\n");
		printf("B – Convert HEX value to RGB\n");
		printf("X – Exit\n\n");
		
		scanf(" %c", &choice);
		system("clear"); //clears console to create immersive experience
		
		switch (choice) {
			case 'A':
			case 'a':
				printf("You chose to Convert RGB value to HEX\n");
				printf("Enter the value of RED (0-255): ");
				scanf("%f", &red);
				printf("Enter the value of GREEN (0-255): ");
				scanf("%f", &green);
				printf("Enter the value of BLUE (0-255): ");
				scanf("%f", &blue);
				
				// conversion formula 
				hex[0] = (int)red / 16;
				hex[1] = (int)red % 16;
				hex[2] = (int)green / 16;
				hex[3] = (int)green % 16;
				hex[4] = (int)blue / 16;
				hex[5] = (int)blue % 16;
				
				printf("\nThe HEX value of the given RGB color is: #");
				for (int i = 0; i < 6; i++) {
					if (hex[i] < 10) {
						printf("%d", hex[i]);
					} else {
						printf("%c", 'A' + (hex[i] - 10));
					}
				}
				printf("\n");
				break;
				
			case 'B':
			case 'b':
				printf("You chose to Convert HEX value to RGB\n");
				printf("Enter a 6 digit hexadecimal color code: ");
				for (int i = 0; i < 6; i++) {
					scanf("%1X", &hex[i]);
				}
				
				// conversion formula
				red = (16 * hex[0]) + hex[1];
				green = (16 * hex[2]) + hex[3];
				blue = (16 * hex[4]) + hex[5];
				
				printf("\nThe RGB values of the given color code are:\n");
				printf("RED = %.0f\n", red);
				printf("GREEN = %.0f\n", green);
				printf("BLUE = %.0f\n", blue);
				break;
				
			case 'X':
			case 'x':
				printf("Thank you for using our Color Code Converter!\n");
				exit(0);
				
			default:
				printf("Invalid input! Please try again.\n");
				break;
		}
	}
	return 0;
}