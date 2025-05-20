//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void decimalToHex(int decimalValue,char hexValue[]);
int hexToDecimal(char hexValue[]);
void reverse(char string[]);

int main(){
	char input[SIZE],output[SIZE];
	int decimal;
	
	printf("Welcome to the curious Hexadecimal Converter!\n");
	printf("Please enter an integer value in decimal form: ");
	scanf("%d",&decimal);
	
	decimalToHex(decimal,output);
	printf("%d in hexadecimal is %s\n",decimal,output);
	
	printf("\nNow let's try converting from hexadecimal to decimal!\n");
	printf("Please enter a hexadecimal value: ");
	scanf("%s",input);
	
	printf("%s in decimal is %d\n",input,hexToDecimal(input));
	
	printf("\nThank you for using the curious Hexadecimal Converter!\n");
	
	return 0;
}

void decimalToHex(int decimalValue,char hexValue[]){
	int remainder,i=0;
	
	while(decimalValue != 0){
		remainder = decimalValue % 16;
		if(remainder<10){
			hexValue[i] = remainder + '0';
		}
		else{
			hexValue[i] = remainder + 55;
		}
		i++;
		decimalValue /= 16;
	}
	hexValue[i] = '\0';
	reverse(hexValue);
}

int hexToDecimal(char hexValue[]){
	int decimalValue = 0,len = strlen(hexValue),i;
	
	for(i = 0;i < len;i++){
		if(hexValue[i] >= '0' && hexValue[i] <= '9'){
			decimalValue += (hexValue[i] - '0') * pow(16,len-i-1);
		}
		else if(hexValue[i] >= 'A' && hexValue[i] <= 'F'){
			decimalValue += (hexValue[i] - 55) * pow(16,len-i-1);
		}
		else if(hexValue[i] >= 'a' && hexValue[i] <= 'f'){
			decimalValue += (hexValue[i] - 87) * pow(16,len-i-1);
		}
		else{
			printf("Invalid input\n");
			exit(1);
		}
	}
	
	return decimalValue;
}

void reverse(char string[]){
	int len = strlen(string),i;
	char temp;
	
	for(i=0;i<len/2;i++){
		temp = string[i];
		string[i] = string[len-i-1];
		string[len-i-1] = temp;
	}
}