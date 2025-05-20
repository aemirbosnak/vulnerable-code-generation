//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
/* D-Lab 9000 alpha version 
 * Copyright(c) 2021 Cygnus Digital Inc.
 */ 

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

int main() 
{ 
	int speed; 
	char input[100]; 

	printf("Welcome to D-Lab 9000 Internet Speed Test\n"); 
	printf("Please enter the download speed: "); 

	fgets(input, 100, stdin); 

	speed = atoi(input); 

	if(speed <= 0) 
	{ 
		printf("Invalid input. Please enter a positive number.\n"); 
		return 1; 
	} 

	printf("Please connect to our blazing fast servers and begin the test.\n"); 
	printf("Testing Download Speed...\n"); 

	/* cryptic code begins */ 

	int i, j, k;
	long double sum = 0.0;

	for(i = 0; i < speed * 100000; i++) 
	{ 
		for(j = 0; j < 100; j++) 
		{ 
			for(k = 0; k < 100; k++) 
			{ 
				sum += 1.002; 
			} 
		} 
	} 

	printf("Download Speed: %.2Lf Mbps\n", sum / 1000000000); 

	/* cryptic code ends */

	printf("Test complete. Thank you for using D-Lab 9000!\n"); 

	return 0; 
}